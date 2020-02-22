#include <iostream>
#include <string>

#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <chrono>

using namespace std::chrono;

void readFile(const char* path){
  std::cout << "filepath: " << path << std::endl;
  // Open File
  struct stat st;
  int fd=open(path, O_RDONLY);
  if(fd == -1 || fstat(fd, &st)){
    std::cout << "Can not access file" << std::endl;
    return;
  }
  std::cout << "File size: " << st.st_size << std::endl;
  int count = 0;
  auto start = high_resolution_clock::now();
  // Allocate a buffer for the file content
  char* data = (char*) mmap(NULL, st.st_size, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
  if(data == MAP_FAILED){
    std::cout << "mmap " << path << " failed!" << std::endl;
    return;
  }
  char* buf = data;
  for(size_t i = 0; i < st.st_size; i++){
    if(data[i] != '\n'){
      //data[i] = '1';
      count++;
    }
  }
  munmap(data, st.st_size);
  close(fd);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop-start);
  std::cout << "Time Used: " << duration.count() << " microseconds" << std::endl;
  std::cout << "count: " << count << std::endl;
  std::cout << "read finish" << std::endl;
}

int main(int argc, char* argv[]){
  if(argc != 2){
    std::cout << "Need a file to parse" << std::endl;
    return 0;
  }  
  readFile(argv[1]);
  return 0;
}

