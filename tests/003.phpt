--TEST--
Let method do() throw an exception.
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
class NoHello {
    public function do() {
        throw new LogicException('No Greeting.');
    }
}
try {
\sample\greet(new NoHello);
} catch (LogicException $e) {
  echo 'LogicException: ', $e->getMessage();
}
?>
--EXPECTF--
LogicException: No Greeting.