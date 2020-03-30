#include "main.h"
/*
WRITTEN BY: backslash
VERSION: Alpha
Citations: 
    - https://blog.kowalczyk.info/articles/pefileformat.html
*/

int main(int argc, LPCSTR argv[]) {
    LPCSTR executable = argv[1];
    hFile = CreateFileA(executable, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (argc == 1){
		std::cout << "usage: MicroscoPE.exe file.exe/file.dll" << std::endl;

		SetConsoleTextAttribute(console, 15);
		return 0;
	}
	else {   

        hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL); //FileMap

        lpFileBase = MapViewOfFile(hFileMapping, FILE_MAP_READ, 0, 0, 0); 

        dHeader = (PIMAGE_DOS_HEADER)lpFileBase;

        pHeader = (PIMAGE_NT_HEADERS)((u_char*)dHeader + dHeader->e_lfanew);
        sHeader = IMAGE_FIRST_SECTION(pHeader);

        //DOS Header
        SetConsoleTextAttribute(console, 15);
        std::cout << "         __"<<std::endl;
        std::cout << "         ||" << std::endl;
        std::cout << "        ====" << std::endl;
        std::cout << "        |  |__" << std::endl;
        std::cout << "        |  |-.\\" << std::endl;
        std::cout << "        |__|  \\\\" << std::endl;
        std::cout << "          ||   ||" << std::endl;
        std::cout << "        ======__|" << std::endl;
        std::cout << "       ________||__" << std::endl;
        std::cout << "      /____________\\" << std::endl;
        std::cout << "  __  __ _                       ___ ___ " <<std::endl;
        std::cout << " |  \\/  (_)__ _ _ ___ ___ __ ___| _ \\ __|" << std::endl;
        std::cout << " | |\\/| | / _| '_/ _ (_-</ _/ _ \\  _/ _| " << std::endl;
        std::cout << " |_|  |_|_\\__|_| \\___/__/\\__\\___/_| |___|" << std::endl;
        std::cout << "" << std::endl;

        /*
        DOS HEADER
        */
        std::cout << "----DOS Header----" << std::endl;
        SetConsoleTextAttribute(console, 12);
        std::cout << "\te_magic: 0x" <<std::hex <<dHeader->e_magic << std::endl;
        std::cout << "\te_cblp: 0x" << std::hex <<dHeader->e_cblp<<std::endl;
        std::cout << "\te_cp: 0x" << std::hex << dHeader->e_cp << std::endl;
        std::cout << "\te_crlc: 0x"<< std::hex << dHeader->e_crlc << std::endl;
        std::cout << "\te_cparhdr: 0x"<< std::hex << dHeader->e_cparhdr << std::endl;
        std::cout << "\te_minalloc: 0x"<< std::hex << dHeader->e_minalloc << std::endl;
        std::cout << "\te_maxalloc: 0x" << std::hex << dHeader->e_maxalloc << std::endl;
        std::cout << "\te_ss: 0x"<< std::hex << dHeader->e_ss << std::endl;
        std::cout << "\te_sp: 0x"<< std::hex << dHeader->e_sp << std::endl;
        std::cout << "\te_csum: 0x" << std::hex << dHeader->e_csum << std::endl;
        std::cout << "\te_ip: 0x" << std::hex << dHeader->e_ip << std::endl;
        std::cout << "\te_cs: 0x"<< std::hex << dHeader->e_cs << std::endl;
        std::cout << "\te_lfarlc: 0x" << std::hex << dHeader->e_lfarlc << std::endl;
        std::cout << "\te_ovno: 0x" << std::hex << dHeader->e_ovno << std::endl;
        std::cout << "\te_res: 0x" << std::hex << dHeader->e_res << std::endl;
        std::cout << "\te_csum: 0x" << std::hex << dHeader->e_csum << std::endl;
        std::cout << "\te_oemid: 0x" << std::hex << dHeader->e_oemid << std::endl;
        std::cout << "\te_oeminfo: 0x" << std::hex << dHeader->e_oeminfo << std::endl;
        std::cout << "\te_res2: 0x" << std::hex << dHeader->e_res2 << std::endl;
        std::cout << "\te_lfanew: 0x" << std::hex << dHeader->e_lfanew<<std::endl;
        /*
        NT HEADER
        */
        SetConsoleTextAttribute(console, 15);
        std::cout << "-----NT Header-----" << std::endl;
        SetConsoleTextAttribute(console, 13);
        std::cout << "\tSignature: 0x" << std::hex << pHeader->Signature << std::endl;
        /*
       OPTIONAL HEADER
       */
        SetConsoleTextAttribute(console, 15);
        std::cout << "-----Optional Header-----" << std::endl;
        SetConsoleTextAttribute(console, 9);
        std::cout << "\tEntry Point: 0x" << std::hex << pHeader->OptionalHeader.AddressOfEntryPoint << std::endl;
        std::cout << "\tBase of Code: 0x" << std::hex << pHeader->OptionalHeader.BaseOfCode << std::endl;
        std::cout << "\tBase of Data: 0x" << std::hex << pHeader->OptionalHeader.BaseOfData << std::endl;
        std::cout << "\tCheckSum: 0x" << std::hex << pHeader->OptionalHeader.CheckSum << std::endl;
        std::cout << "\tData Directory: 0x" << std::hex << pHeader->OptionalHeader.DataDirectory << std::endl;
        std::cout << "\tCharcteristics: " << pHeader->OptionalHeader.DllCharacteristics << std::endl;
        std::cout << "\tFile Alignment: 0x" << std::hex << pHeader->OptionalHeader.FileAlignment << std::endl;
        std::cout << "\tImage Base: 0x" << std::hex << pHeader->OptionalHeader.ImageBase << std::endl;
        std::cout << "\tLoader Flags: 0x" << std::hex << pHeader->OptionalHeader.LoaderFlags << std::endl;
        std::cout << "\tMagic: 0x" << std::hex << pHeader->OptionalHeader.Magic << std::endl;
        std::cout << "\tMajor Image Version: "<< pHeader->OptionalHeader.MajorImageVersion << std::endl;
        std::cout << "\tMajor Linker Version: " << pHeader->OptionalHeader.MajorLinkerVersion<< std::endl;
        std::cout << "\tMajor System Version: "<<pHeader->OptionalHeader.MajorOperatingSystemVersion << std::endl;
        std::cout << "\tMinor Image Version: "<< pHeader->OptionalHeader.MinorImageVersion<< std::endl;
        //std::cout << "\tMinor Linker Version: "<< pHeader->OptionalHeader.MinorLinkerVersion << std::endl;
        std::cout << "\tMinor System Version :"  << pHeader->OptionalHeader.MinorOperatingSystemVersion << std::endl;
        std::cout << "\tMinor SubSystem Version :" << pHeader->OptionalHeader.MinorSubsystemVersion<< std::endl;
        std::cout << "\tNumber of RVA and Sizes:" << pHeader->OptionalHeader.NumberOfRvaAndSizes<< std::endl;
        std::cout << "\tSection Alignment: 0x"<<std::hex<< pHeader->OptionalHeader.SectionAlignment<< std::endl;
        std::cout << "\tSize of Code: " << pHeader->OptionalHeader.SizeOfCode << std::endl;
        std::cout << "\tSize of Header: " << pHeader->OptionalHeader.SizeOfHeaders << std::endl;
        std::cout << "\tSize of Heap Commit: " << pHeader->OptionalHeader.SizeOfHeapCommit<< std::endl;
        std::cout << "\tSize of Heap Reserve: " << pHeader->OptionalHeader.SizeOfHeapReserve << std::endl;
        std::cout << "\tSize of Image: " << pHeader->OptionalHeader.SizeOfImage<< std::endl;
        std::cout << "\tSize of Initialized Data: " << pHeader->OptionalHeader.SizeOfInitializedData << std::endl;
        std::cout << "\tSize of Stack Commit: " << pHeader->OptionalHeader.SizeOfStackCommit<< std::endl;
        std::cout << "\tSize of Reserve: " << pHeader->OptionalHeader.SizeOfStackReserve << std::endl;
        std::cout << "\tSize of Unitialized Data: " << pHeader->OptionalHeader.SizeOfUninitializedData << std::endl;
        std::cout << "\tSubsystem: " << pHeader->OptionalHeader.Subsystem << std::endl;
        /*
        FILE HEADER
        */
        SetConsoleTextAttribute(console, 15);
        std::cout << "-----File Header-----" << std::endl;
        SetConsoleTextAttribute(console, 8);
        std::cout << "\tCharacteristics Count: " << pHeader->FileHeader.Characteristics << std::endl;
        std::cout << "\tMachine: " << pHeader->FileHeader.Machine << std::endl;
        std::cout << "\tSection Count: " << pHeader->FileHeader.NumberOfSections << std::endl;
        std::cout << "\tNumber of Symbols: " << pHeader->FileHeader.NumberOfSymbols << std::endl;
        std::cout << "\tPointer to Symbol Table: 0x" << std::hex << pHeader->FileHeader.PointerToSymbolTable << std::endl;
        std::cout << "\tSize of Optional Header: " << pHeader->FileHeader.SizeOfOptionalHeader << std::endl;
        std::cout << "\tTime Date Stamp: " << pHeader->FileHeader.TimeDateStamp << std::endl;
        std::cout << "\tNumber of Lines: " << sHeader->NumberOfLinenumbers << std::endl;
        std::cout << "\tNumber of Relocations: " << sHeader->NumberOfRelocations << std::endl;
        std::cout << "\tPointer to Raw Data: 0x" << std::hex << sHeader->PointerToRawData << std::endl;
        std::cout << "\tSize of Raw Data:" << sHeader->SizeOfRawData << std::endl;
        std::cout << "\tVirtual Address: 0x" << std::hex << sHeader->VirtualAddress << std::endl;

        SetConsoleTextAttribute(console, 15);
        std::cout << "---Section Header---" << std::endl;
        SetConsoleTextAttribute(console, 11);
        for (UINT i = 0; i < pHeader->FileHeader.NumberOfSections; i++, ++sHeader) {
            std::cout << "\tSection "<<i <<": "  << sHeader->Name << std::endl;
        }
        std::cout << "\tNumber of Sections: " << pHeader->FileHeader.NumberOfSections << std::endl;

        SetConsoleTextAttribute(console, 10);
        SetConsoleTextAttribute(console, 15);
        std::cout << "----Other----" << std::endl;
        SetConsoleTextAttribute(console, 14);
        std::cout << "\tMore To Come Later: " << std::endl;
        std::cout << "\tFileSize: COMING SOON" << std::endl;
        std::cout << "\tFileHash: COMING SOON" << std::endl;
        std::cout << "\tData Directories: COMING SOON" << std::endl;
        std::cout << "\tAdd Short Description: COMING SOON" << std::endl;



        SetConsoleTextAttribute(console, 15);

	}
	
}
