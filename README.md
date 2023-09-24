# php-extension-sample
PHP Extension Feature Samples

This repository is a collection of sample features for a php extension. 
Each branch implements a single feature. Basically I add my tests as branches 
as I am learning and experimenting.

The minimum version is PHP 8. I am not going to implement BC for older versions.

## Basic Skeleton

This branch contains the basic files and code to get the extension to compile and be
available in PHP. It does not contain any functionality.

After compiling and configuring the extension run `php --re sample`. The output should 
comparable to:

```
Extension [ <persistent> extension #26 sample version 1.0 ] {
}
```
