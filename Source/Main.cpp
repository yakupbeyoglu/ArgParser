#include <iostream>
#include "Headers/KeyStore.h"

int main() {
    ArgumentParser::KeyStore keystore;
    keystore.Add("test", 3);
    keystore.Delete("test");
    return 0;
}
