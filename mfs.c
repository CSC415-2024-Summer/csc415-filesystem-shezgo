// cwd is a pointer we can make at runtime i.e: "DirectoryEntry * cwd " - austin 
char * fs_getcwd(char *buf, size_t size){
	printf("\n---Get Curent Working Directory---\n");
	
	if(cwd == NULL)
	{
		printf("fill this if statement with eroorhandling")
	}
	
	// copy th ecurrent working directory into our buffer 
	strcpy(buffer, cwd->name);
	//checking ret val for the new buffer 
	return buffer;
}

int fs_setcwd(char *buff){
	// return value of this strcpy is the destination
					// change to our variable  [BLOCKSIZE]
	// char * pathToParse is how we handle the  "/" string split in directories 
	char pathToParse[BLOCK_SIZE];
	strcpy(pathToParse, buffer);
	parsedInfo* info = malloc(sizeof(parsedInfo));
	parsePath(cwd, root, pathToParse, info);
	printf("Set Cwd lastElementIndex: %d\n", info->lastElementIndex);
	// Checking to see if the last element exists and is an element. 
	if(info->lastElementIndex > 0){
		//parent location
		directoryEntry * cwdPtr = loadDir(info->parent->entries[info->lastElementIndex]);
		// have to copy the buffer to cwd 
		
		cwd = cwdPtr;
		printf(cwd);
		return 0;
	} else {
		// Error message
		printf("Error in setcwd. Check line 128 of mfs.c");
		return -1;
	}
}