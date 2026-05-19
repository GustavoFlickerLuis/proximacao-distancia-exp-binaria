library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.FLOAT_PKG.ALL;             

entity distancia_euclidiana is
    Port (
        x1, y1    : in  float64;   
        x2, y2    : in  float64;
        resultado : out float64
    );
end distancia_euclidiana;

architecture Behavioral of distancia_euclidiana is

    function distanciaEuclidiana(x1, y1, x2, y2 : float64) return float64 is
        variable dx : float64;
        variable dy : float64;
    begin
        dx := (x1 - x2) * (x1 - x2);  
        dy := (y1 - y2) * (y1 - y2);   
        return sqrt(dx + dy);          
    end function;

begin
    resultado <= distanciaEuclidiana(x1, y1, x2, y2);
end Behavioral;
