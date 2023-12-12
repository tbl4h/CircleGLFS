//
// Created by mic on 12.12.23.
//

#include "Shader.h"

using std::ifstream;

string getFileContent(const char * filename){
    ifstream in(filename, std::ios::binary);
    if(in)
    {
        string contents;
        // Move current stream possition of 0 bytes in stream begins from the end of the stream.
        in.seekg(0,std::ios::end);
        // Resize the size of the content string to the size of the stream (in bytes).
        contents.resize(in.tellg());
        // Move the stream counter possition to the begin.
        in.seekg(0, std::ios::beg);
        // Read the stream content and write it to the content string.
        // Zlikwidować ostrzeżenie ClangTidy
        bigbug
        in.read(&contents[0],contents.size());
        // Close the in stream.
        in.close();
        return (contents);
    }
    throw(errno);
}
