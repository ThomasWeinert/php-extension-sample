--TEST--
Call method "do" on object argument without that method.
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
try {
    \sample\greet(new stdClass);
} catch (Error $e) {
    echo "Error: ", $e->getMessage();
}
?>
--EXPECTF--
Error: Invalid callback stdClass::do, class stdClass does not have a method "do"