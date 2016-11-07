--TEST--
Encode an instance of Sample\HelloWorld as Json
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
echo json_encode(new Sample\HelloWorld(), JSON_PRETTY_PRINT);
?>
--EXPECT--
"Hello World!"