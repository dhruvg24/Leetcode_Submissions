# Write your MySQL query statement below
select distinct author_id as id from Views where author_id = viewer_id order by author_id;

# for viewing condition its given that author id shd be same as viewer id