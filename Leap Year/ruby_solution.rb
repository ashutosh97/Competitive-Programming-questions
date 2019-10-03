def leap(year)
  puts year %400 == 0 || year %4 == 0 && !(year %100 == 0)
end

leap(1996) #expect true
leap(2000) #expect true
leap(2015) #expect false
leap(1800) #expect false
