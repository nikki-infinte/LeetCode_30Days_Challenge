# Write your MySQL query statement below

with maxOut as(
    select max(num) as num
    from MyNumbers
    group by num
    having count(num) = 1
)

select max(num) as num
from maxOut;