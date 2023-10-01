--TEST--
Check for sample presence
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
echo \Sample\helloWorld();
?>
--EXPECT--
Hello World!
