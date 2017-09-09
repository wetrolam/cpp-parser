Dependency
----------

libclang

### Install Libclang on Ubuntu

`sudo apt install clang`

`sudo apt install libclang-dev`

`sudo apt install libclang1`


### Example of Libclang Settings

add include directory: 

`/usr/lib/llvm-3.8/include/`

add linker directory: 

`/usr/lib/llvm-3.8/lib`

add linker options: 

`-lclangTooling -lclangFrontendTool -lclangFrontend -lclangDriver -lclangSerialization -lclangCodeGen -lclangParse -lclangSema -lclangStaticAnalyzerFrontend -lclangStaticAnalyzerCheckers -lclangStaticAnalyzerCore -lclangAnalysis -lclangARCMigrate -lclangRewrite -lclangRewriteFrontend -lclangEdit -lclangAST -lclangLex -lclangBasic -lclang`

