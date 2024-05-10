-- 코드를 입력하세요
SELECT ANIMAL_ID,	NAME
from animal_outs
where ANIMAL_ID not in (select Animal_id from animal_ins)
order by ANIMAL_ID,	NAME;