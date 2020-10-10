<?php
for ($i = 1; $i <= 100; $i++)
{
    if (!($i % 15))
        echo "fizzbuzz\n";
    else if (!($i % 3))
        echo "fizz\n";
    else if (!($i % 5))
        echo "buzz\n";
    else
        echo "$i\n";
}
?>
