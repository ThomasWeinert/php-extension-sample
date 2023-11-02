--TEST--
Call method "do" on object argument without that method.
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
try {
    \sample\countdown(new stdClass);
} catch (Error $e) {
    echo "Error: ", $e->getMessage();
}
?>
--EXPECTF--
Fatal error: Couldn't find implementation for method stdClass::do in Unknown on line 0