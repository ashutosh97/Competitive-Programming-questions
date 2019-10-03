def abbreviate(string)
  string_arr = string.scan(/\b\w/)
  string_arr.join.upcase
end


# begin
# >> abbreviate("Portable Network Graphics")
# => "PNG"
# >> abbreviate("Ruby on Rails")
# => "ROR"
# >> abbreviate("GNU Image Manipulation Program")
# => "GIMP"
