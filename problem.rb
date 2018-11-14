require "numo/narray"
ary10 = Numo::DFloat[65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70]
ary11 = Numo::DFloat[44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84]

print "理科 平均点:", ary10.mean, "  標準偏差:", ary10.stddev, "  合計点:", ary10.sum

print "\n理科 "
for i in 0..19 
print 50+(ary10[i]-ary10.mean)/2," "
end
print "\n英語 "
for i in 0..19 
print 50+(ary11[i]-ary11.mean)/2," "
end 
print "\n理科 ",ary10.sort.to_a.reverse
print "\n英語 ",ary11.sort.to_a.reverse
