--TEST--
Check for sample presence
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
echo "sample extension is available";
?>
--EXPECT--
sample extension is available
