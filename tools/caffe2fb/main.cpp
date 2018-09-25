#include "net.h"
#include "net_parser.h"
#include "memory_list_parser.h"
using namespace nvdla;
int main()
{
    nvdla::NetParser lenet;

    lenet.load_caffe_net("lenet.param","lenet.bin");
    lenet.build_nvdla_net();
    TaskListParser* tlp = new TaskListParser(&lenet);    
    MemoryListParser* memlist = new MemoryListParser(&lenet, tlp);
    memlist->buildList();    
    memlist->debugMemList();   
    return 0;
}
