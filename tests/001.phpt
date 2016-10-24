--TEST--
Check for sample presence
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
echo \sample\answer();
?>
--EXPECT--
42
