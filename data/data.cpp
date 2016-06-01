#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "data.hpp"

std::vector<std::string> split(const std::string &s)
{
	/* Tokenizes (i.e. isolates words in sentences and adds to vector) similar to
 	 * .split() function in python
 	 */ 
	
	std::vector<std::string> elems;
	std::stringstream ss(s);
	std::string item;

	while (std::getline(ss, item, ' ')) {
		if (!item.empty()) {
            		elems.push_back(item);
        	}
    	}

	return elems;
}

int gaplessLength(std::string read) {
	read.erase(std::remove(read.begin(), read.end(), '-'), read.end());
	return read.length(); 
}

ReadInfo::ReadInfo(std::string readName, std::string refOrientation, std::string readOrientation, 
			std::string refStart, std::string refSrcSize)
{
	name = readName;
	refOrient = refOrientation;
	readOrient = readOrientation;
	start = refStart;
	srcSize = refSrcSize;
}

void ReadInfo::reset(std::string readName, std::string refOrientation, std::string readOrientation,
			std::string refStart, std::string refSrcSize)
{
	name = readName;
	refOrient = refOrientation;
	readOrient = readOrientation;
	start = refStart;
	srcSize = refSrcSize;
}

std::string ReadInfo::getName()
{
	return name;
}

std::string ReadInfo::getRefOrient()
{
	return refOrient;
}

std::string ReadInfo::getReadOrient()
{
	return readOrient;
}

std::string ReadInfo::getStart()
{
	return start;
}

std::string ReadInfo::getSrcSize()
{
	return srcSize;
}

MafFile::MafFile(std::string fileName)
{
	filename = fileName;
	std::ofstream file (filename, std::ios::out | std::ios::trunc);
	
	// Write the header in the file upon first opening
	if (file.is_open()) {
		file << "track name=" << filename << "\n";	
		file << "##maf version=1\n";
		file << "# tba.v8\n";
		file << "\n";
		file.close();
	} else {
		std::cerr << "Unable to create MAF file.\n";
	}
}

void MafFile::addReads(Alignments alignments, ReadInfo readInfo)
{
	/* Reads data from alignment and readInfo objects and writes to file
 	 * in MAF format as described in https://genome.ucsc.edu/FAQ/FAQformat.html
 	 */ 

	std::string ref = alignments.getRef();
	std::string ulr = alignments.getUlr();
	std::string clr = alignments.getClr();

	std::string refName = "reference"; 
	std::string uName = readInfo.getName() + ".uncorrected";
	std::string cName = readInfo.getName() + ".corrected";

	std::string refStart = readInfo.getStart();
	int uStart = 0;
	int cStart = 0;
 
	int refSize = gaplessLength(ref);
	int uSize = gaplessLength(ulr);
	int cSize = gaplessLength(clr);

	std::string refSrcSize = readInfo.getSrcSize();
	int uSrcSize = uSize;
	int cSrcSize = cSize;

	std::string refOrient = readInfo.getRefOrient();
	std::string readOrient = readInfo.getReadOrient();

	std::ofstream file (filename, std::ios::out | std::ios::app);


	if (file.is_open())
	{
		file << "a\n";
		file << "s " << refName << " " << refStart << " " << refSize << " " << refOrient << " " 
			<< refSrcSize << " " << ref << "\n";
		file << "s " << uName << " " << uStart << " " << uSize << " " << readOrient << " " << uSrcSize << " " << ulr << "\n";
		file << "s " << cName << " " << cStart << " " << cSize << " " << readOrient << " " << cSrcSize << " " << clr << "\n";
		file << "\n";
		file.close();
	} else {
		std::cerr << "Unable to add reads to MAF file\n";
	}
}
