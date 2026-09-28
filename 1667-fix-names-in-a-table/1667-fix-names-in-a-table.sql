# Write your MySQL query statement below
SELECT user_id,    # user_id select
CONCAT(
    UPPER(SUBSTRING(name,1,1)),
    LOWER(SUBSTRING(name, 2)) ) AS name     # name select + format
FROM Users
ORDER BY user_id