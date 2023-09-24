--TEST--
Call function with different (mixed) argument types
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
$fh = fopen(__FILE__, 'r');
echo \sample\output($fh), "\n";
fclose($fh);
?>
--EXPECT--
Resource id #5
