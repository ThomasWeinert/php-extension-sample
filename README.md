# PHP Extension Feature Samples

This repository is a collection of sample features for a php extension. 
Each [branch](https://github.com/ThomasWeinert/php-extension-sample/branches/all) implements 
a single feature. Basically I add my tests as branches as I am learning and experimenting.

The minimum version is PHP 8 (originally PHP 7). I am not going to implement BC for older versions.

## Talk About PHP Core And Extension Development

Join the [Stackoverflow Chat Room 11](https://chat.stackoverflow.com/rooms/11/php) 

## Compiling An Extension

Inside the extension directory:

1. Initialize with `phpize`
2. Configure with `./configure`
3. Compile with `make`

## Testing You Extension

PHP uses PHPT files for tests. The format is documented on the 
[phpQA pages](https://qa.php.net/write-test.php). 

`make test` will compile your extension and run the tests.
 
## Argument Information

PHP needs argument information for the functions and methods. Since PHP 8 you can define 
the stubs in PHP and generate the argument information from them.

Create a php file that ends with `.stub.php`. Define the your extension API as empty stubs.
Call `build/gen_stubs.php` from the main php repository inside the extension directory to 
generate/update the argument information.

```shell
$ ../php-src/build/gen_stubs.php
```

If all goes well this will result in a C header file that ends with `_arginfo.h` for each stub file that 
you can include in the extension C file.
