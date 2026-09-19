# Write your MySQL query statement below
Select email as Email
FROM Person
Group By email
HAVING Count(*) > 1;

