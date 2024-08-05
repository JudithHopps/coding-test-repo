-- 코드를 입력하세요

select CONCAT('/home/grep/src/', U.BOARD_ID , '/' , U.FILE_ID, U.File_NAME,U.FILE_EXT) as FILE_PATH

from  USED_GOODS_FILE as U 
where U.BOARD_ID = (
    SELECT BOARD_ID from USED_GOODS_BOARD
    order by VIEWS desc
    limit 1
    ) 
order by FILE_PATH desc;

    
