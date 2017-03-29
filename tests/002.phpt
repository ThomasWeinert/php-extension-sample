--TEST--
Call method "do" on object argument without that method.
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
class Hello {
}

try {
  \sample\greet(new Hello("World"));
} catch (\Throwable $e) {
  var_dump($e);
}
?>
--EXPECT--
Warning: sample\greet(): Unable to call  method do() on argument in /home/vagrant/data/ext/sample/tests/002.php on line 5
