#include <node.h>
#include <v8.h>
#include <nan.h>
#include "SpookyV2.h"
#include <stdio.h>
#include <inttypes.h>

void Hash128(const Nan::FunctionCallbackInfo<v8::Value>& args) {
  
    uint64 hash1 = *((uint64 *) node::Buffer::Data(args[1]->ToObject()));
    uint64 hash2 = *((uint64 *) node::Buffer::Data(args[2]->ToObject()));
    v8::Local<v8::Object> inputV8Buf = args[0]->ToObject();
    char* inputBuf = (char*) node::Buffer::Data(inputV8Buf);
    size_t inputLen = node::Buffer::Length(inputV8Buf);
    
    SpookyHash::Hash128(inputBuf, inputLen, &hash1, &hash2);

    char *outputBuf = (char *) malloc(16);
    memcpy(outputBuf, &hash1, 8);
    memcpy(outputBuf + 8, &hash2, 8);

    args.GetReturnValue().Set(Nan::NewBuffer(outputBuf, 16).ToLocalChecked());

}

void Init(v8::Local<v8::Object> exports) {
    exports->Set(Nan::New("hash128").ToLocalChecked(), Nan::New<v8::FunctionTemplate>(Hash128)->GetFunction());
}

NODE_MODULE(binding, Init);

