--TEST--
Check for phpinfo output using reflection
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
$ext = new ReflectionExtension('sample');
$ext->info();
?>
--EXPECT--
sample

sample support => enabled
1. => Basic extension
