--TEST--
Check for sample presence
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
echo \Sample\answer();
?>
--EXPECT--
42
