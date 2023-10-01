--TEST--
Create and use sample resource
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php 
$r = Sample\createResource();
Sample\useResource($r);
?>
--EXPECT--
Number: 42
