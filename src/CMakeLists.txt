# 将所有的源文件添加到一个变量中
#aux_source_directory(. SRC_LIST)
set(SRC_LIST
        mprpcapplication.cc
        mprpcconfig.cc
        rpcheader.pb.cc
        rpcprovider.cc
        mprpcchannel.cc
        mprpccontroller.cc
        logger.cc
        zookeeperutil.cc
       )

#set(SRC_LIST mprpcapplication.cc mprpcconfig.cc )
# STATIC 静态库
add_library(mprpc STATIC  ${SRC_LIST})
target_link_libraries(mprpc muduo_net muduo_base   pthread zookeeper_mt)

# sudo find /usr -name "libmuduo*"