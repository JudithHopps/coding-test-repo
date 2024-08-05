-- 코드를 작성해주세요

SELECT COUNT(*) AS count
FROM ecoli_data
WHERE !(genotype & (1<<1)) AND (genotype & (1) OR genotype & (1<<2));
