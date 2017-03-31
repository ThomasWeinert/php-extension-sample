--TEST--
Call method "do" on object argument without that method.
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
\sample\greet(new stdClass);
?>
--EXPECTF--
Fatal error: sample\greet(): Unable to call method do() on object argument in %s002.php on line %d
