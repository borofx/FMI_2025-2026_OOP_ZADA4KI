#include <iostream>
#include <cstring>

class CompressionStrategy{
    public:
        virtual void compress(const char* input, char* output, int& output_size) = 0;
        virtual void decompress(const char* input, char* output, int& output_size) = 0;
        virtual ~CompressionStrategy() {}
};

class RLECompression : public CompressionStrategy{
    public:
        void compress(const char* input, char* output, int& output_size) override{}
        void decompress(const char* input, char* output, int& output_size) override{}
};
class XORCompression : public CompressionStrategy{
    private:
        char key;
    public:
    XORCompression(char k) : key(k) {}
        void compress(const char* input, char* output, int& output_size) override{}
        void decompress(const char* input, char* output, int& output_size) override{}
};
class CompressionFactory{
    public:
        static CompressionStrategy* create(const char* type){
            if(strcmp("XOR", type) == 0)
                return new XORCompression('X');
            if(strcmp("RLE", type) == 0)
                return new RLECompression();
            return nullptr;
        }
};
class FileCompressor{
    private:
        CompressionStrategy* strategy;
    public:
        FileCompressor(CompressionStrategy* s) : strategy(s) {}
        void compressFile(const char* input, char* output, int& size) {
            strategy->compress(input, output, size);
        }
        void decompressFile(const char* input, char* output, int& size) {
            strategy->decompress(input, output, size);
        }
        ~FileCompressor(){
            delete strategy;
            strategy = nullptr;
        }
};

int main(){
    
}