counter = 0

while counter < 100
counter += 1
  if (counter % 3 == 0) && (counter % 5 == 0)
    puts("Fizz Buzz")
  elsif counter % 3 == 0
    puts("Fizz")
  elsif (counter % 5 == 0)
    puts("Buzz")
  else puts(counter)
  end
end
break
