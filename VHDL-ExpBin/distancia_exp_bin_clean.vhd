library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity distancia_exp_bin is
    Port (
        x1, y1    : in  signed(15 downto 0);
        x2, y2    : in  signed(15 downto 0);
        resultado : out signed(15 downto 0)
    );
end distancia_exp_bin;

architecture Behavioral of distancia_exp_bin is

    function distanciaExpBinAuto(x1, y1, x2, y2 : signed(15 downto 0)) return signed is
        variable dx          : signed(15 downto 0);
        variable dy          : signed(15 downto 0);
        variable A           : signed(15 downto 0);
        variable B           : signed(15 downto 0);
        variable aproximacao : signed(15 downto 0);
        variable shift       : integer;
    begin
        dx := abs(x1 - x2);
        dy := abs(y1 - y2);

        if dx > dy then A := dx; B := dy;
        else             A := dy; B := dx;
        end if;

        aproximacao := A;
        shift := 1;

        while shift_right(B, shift) > 0 loop
            if (shift - 1) mod 2 = 0 then
                aproximacao := aproximacao + shift_right(B, shift);
            else
                aproximacao := aproximacao - shift_right(B, shift);
            end if;
            shift := shift + 1;
        end loop;

        return aproximacao;
    end function;

begin
    resultado <= distanciaExpBinAuto(x1, y1, x2, y2);
end Behavioral;
