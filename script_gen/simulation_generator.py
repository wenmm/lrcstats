import sys
import getopt
import read_config

def writeHeader(file, scriptPath):
	# Write the generic header lines for PBS scripts
	line = "#!/bin/bash\n"
	file.write(line)

	# Write the resources
	resources = ['walltime=12:00:00', 'mem=8gb', 'nodes=1:ppn=4']
	for resource in resources:
		line = "PBS -l %s\n" % (resource)
		file.write(line)

	# Specify the location of the epilogue script
	line = "#PBS -l epilogue=%s/scripts/epilogue.script\n" % (variables["lrcstats"])
	file.write(line)

	# Email to send info about jobs
	line = "#PBS -M %s\n" % ( variables["email"] )
	file.write(line)
	
	# Only send emails when jobs are done or aborted
	# Epilogue info all in one file
	line = "#PBS -m ea\n" \
		"#PBS -j oe\n"	
	file.write(line)

	# Epilogue script output path
	line = "#PBS -o %s.out\n" % (scriptPath)
	file.write(line)

def simulateArtShortReads(genome, coverage):
	# Given the genome and coverage, make PBS script to simulate short reads
	scriptPath = "%s/simulate_%s_short_d%s.pbs" % (jobsDir, genome, coverage) 
	with open(scriptPath, 'w') as file:
		writeGenericHeader(file)

		# Name of the job
		line = "#PBS -N simulate_%s_short_d%s\n" % (genome, coverage)
		file.write(line)

		file.write('\n')

		# Write genome name and coverage
		coverage = "cov=%s\n" % (coverage)

		genome = "genome=%s\n" % (genome)

		genomeDir = "genomeDir=%s/${genome}\n" % (variables["data"], genome)

		# where the art executable is
		artPath = "art=%s/art_illumina\n" % (variables["art"])

		fq2fastqPath = "fq2fastq=%s/src/preprocessing/fq2fastq.py\n" % (variables["lrcstats"])

		merge_files = "merge_files=%s/src/preprocessing/merge_files/merge_files.py\n" % (variables["lrcstats"])

		line = coverage + genome + genomeDir + artPath + fq2fastqPath + merge_files
		file.write(line)

		line = "outputDir=$genomeDir/art/short-d%{cov}\n" \
			"outputPrefix=$outputDir/${genome}-short-paired-d${cov}\n" \
			"ref=$genomeDir/${genome}_reference.fasta\n" \
			"\n" \
			"mkdir -p $outputDir\n" \
			"$art -p -i $ref -l 100 -f $cov -o $outputPrefix\n" \
			"\n" \
			"python $fq2fastq -i $outputDir\n"
			"\n" \
			"short1=${outputPrefix}1.fastq\n" \
			"short2=${outputPrefix}2.fastq\n" \
			"shortMerged=${outputPrefix}-merged.fastq\n" \
			"\n" \
			"python $merge_files -i $short1 -i $short2 -o $shortMerged\n"
		file.write(line)

def simulateSimlordLongReads(genome, coverage):
	# Given the genome and coverage, make PBS script to simulate short reads
	scriptPath = "%s/simulate_%s_long_%s.pbs" % (jobsDir, genome, coverage) 
	with open(scriptPath, 'w') as file:
		writeGenericHeader(file)

		# Name of the job
		line = "#PBS -N simulate_%s_long_%s\n" % (genome, coverage)
		file.write(line)

		file.write('\n')

		# Write genome name and coverage
		coverage = "cov=%s\n" % (coverage)
		file.write(coverage)

		genome = "genome=%s\n" % (genome)
		file.write(genome)

		genomeDir = "genomeDir=%s/${genome}\n" % (scratchDir, genome)
		file.write(genomeDir)

		outputDir = "outputDir=$genomeDir/simlord/long-d${cov}\n"
		file.write(outputDir)

		outputPrefix = "outputPrefix=$outputDir/${genome}-long-d${cov}\n" 
		file.write(outputPrefix)

		reference = "$genomeDir/${genome}_reference.fasta\n" 
		file.write(reference)

		if genome is "ecoli":
			fastq = ecoliFastq
		elif genome is "yeast":
			fastq = yeastFastq
		elif genome is "fly":
			fastq = flyFastq

		fastqPath = "fastq=$genomeDir/%s\n" % (fastq)
		file.write(fastqPath)

		file.write('\n')

		reads4coverage="reads4coverage=/home/seanla/Projects/lrcstats/src/preprocessing/reads4coverage.py\n"
		file.write(reads4coverage)

		simlord = "simlord=/home/seanla/Software/anaconda2/envs/simlord/bin/simlord\n"
		file.write(simlord)

		file.write('\n')

		mkdir = "mkdir -p $outputDir\n"
		file.write(mkdir)

		reads = "reads=$(python $reads4coverage -c $cov -i $fastq -r $ref)\n"
		file.write(reads)

		command = "$simlord -n $reads -sf $fastq -rr $ref $outputPrefix\n"
		file.write(command)

		file.write('\n')

		sam2mafPath = "sam2maf=/home/seanla/Projects/lrcstats/src/preprocessing/sam2maf/sam2maf.py\n"
		file.write(sam2mafPath)
	
		samPath = "sam=${outputPrefix}.sam\n"
		file.write(samPath)

		mafPath = "maf=${sam}.maf\n"
		file.write(mafPath)	

		file.write('\n')

		sam2mafCommand = "python $sam2maf -r $ref -s $sam -o $maf\n"
		file.write(sam2mafCommand)

if __name__ == "__main__":

	'''
	# Global variables
	jobsDir = "/home/seanla/Jobs/lrcstats/simulate"
	scratchDir = "/global/scratch/seanla/Data"
	ecoliFastq = "SRR1284073.fastq"
	yeastFastq = "SRR1284073-1284662_combined.fastq"
	flyFastq = "SRR1204085.fastq"
	'''

	helpMessage = "Generate PBS job scripts for simulating DNA reads."
	usageMessage = "Usage: %s [-h help and usage] [-f fly] [-e ecoli] [-y yeast] [-l simulate long reads] [-s simulate short reads] [-d depth of coverage] [-a simulate all coverages]" % (sys.argv[0])

	options = "hfeylsdca:"

	try:
		opts, args = getopt.getopt(sys.argv[1:], options)
	except getopt.GetoptError:
		print "Error: unable to read command line arguments."
		sys.exit(2)

	if len(sys.argv) == 1:
		print usageMessage
		sys.exit(2)

	simLong = False
	simShort = False
	coverage = None
	allCov = False

	doYeast = False
	doEcoli = False
	doFly = False

	genomes = []
	coverage = None

	configPath = None

	for opt, arg in opts:
		# Help message
		if opt == '-h':
			print helpMessage
			print usageMessage
			sys.exit()
		elif opt == '-f':
			doFly = True
			genomes.append('fly')
		elif opt == '-e':
			doEcoli = True
			genomes.append('ecoli')
		elif opt == '-y':
			doYeast = True
			genomes.append('yeast')
		elif opt == '-s':
			simShort = True
		elif opt == '-l':
			simLong = True
		elif opt == '-d':
			coverages = [arg]
		elif opt == '-a':
			allCov = True
		elif opt == '-c':
			configPath = arg

	optsIncomplete = False

	if not doFly or not doYeast or not doEcoli:
		print "Please select a genome to simulate."
		optsIncomplete = True
	if not simLong and not simShort:
		print "Please select which type of reads you would like to simulate."
		optsIncomplete = True
	if simLong and simShort and not allCov:
		print "You can only simulate both short and long reads by specifying simulating all coverages."
		optsIncomplete = True
	if configPath is None:
		print "Please provide the path to the configuration file."
		optsIncomplete = True	

	if optsIncomplete:
		print usageMessage
		sys.exit(2)

	variables = get_config.getConfig(configPath)

	if simLong:
		coverages = ['10', '20', '50', '75']
	elif simShort:
		coverages = ['50', '100', '200']

	for genome in genomes:
		for coverage in coverages:
			if simLong:
				simulateSimlordLongReads(genome, coverage)
			elif simShort:
				simulateArtShortReads(genome, coverage) 
