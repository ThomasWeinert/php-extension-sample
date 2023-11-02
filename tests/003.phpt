--TEST--
Let method do() throw an exception.
--SKIPIF--
<?php if (!extension_loaded("sample")) print "skip"; ?>
--FILE--
<?php
class Target {
    public function do($name) {
        throw new LogicException('No Greeting.');
    }
}
try {
\sample\countdown(new Target);
} catch (LogicException $e) {
  echo 'LogicException: ', $e->getMessage();
}
?>
--EXPECTF--
LogicException: No Greeting.