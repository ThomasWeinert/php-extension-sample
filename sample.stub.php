<?php

namespace Sample {

  class Greeting {

    public string $name;

    public function __construct(string $name) {
    }

    public function hello(): void {
    }
  }

  function getGreeting(): Greeting {
  }

}