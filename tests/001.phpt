--TEST--
Output Sample\SAMPLE_INT constant and expect 42
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
echo Sample\SAMPLE_INT;
?>
--EXPECT--
42