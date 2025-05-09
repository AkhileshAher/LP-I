start 101
macro ABC
movem areg, a
mend
macro mno
add areg, a
mend
ABC 
mno
comp creg, n
end
