C_Labs
### ������������ ����� 14. ���� ����� ###

����� ������������ ������ �������� ���������� ���� ������� ,
����������� �������� ��������� ���� � ����������� �������� � ������� BMP.
��������� ���������� ���� ���������� �������������� ������������.

������������ ������ ������ ���� ��������� � ���� ����������� ���������� ������������
� �������� ���������� ��������� ���������: 
1)--input input_file.bmp 
��� input_file.bmp - ����������� �������� � ������� bmp, �������� 
��������� �������� (������ ���������) ���� 
2)--output dir_name 
�������� ���������� ��� �������� ��������� ���� � ���� ����������� ��������
3) --max_iter N
������������ ����� ��������� ������� ����� ����������� ���������. �������������� ��������, 
��-��������� �������������
4) --dump_freq N
������� � ������� ��������� ������ ��������� ��������� ���� ��������. �������������� ��������, ��-��������� ����� 1

��������� ������ ��������������� �������������� ��������, ������� ����� ��������� �� ����� �� ������ � ��������� �� ������������. 

### ������������ ����� 15. ��������� ������. ###

����� ������������ ������ �������� ���������� ��������� �� ������������� � ���������� ���������� ������ � ���� �����. ��������� ������
����� ������������ ��������� (���� � �����) ��������� ������ � ����� � ����������� *.arc
����� ������������� �������� �����, �������� ���������� ������������ �����
������������� ������ ������ ����������� � ������
������� � ��������� ������ ��� �������������  � ������� ��������� �������� (������������ �������, ����������� ��� �������)

��������� ������ ���� �������� � ���� ����������� ����������, ������������ � �������� ���������� ��������� ���������

1) --file  FILE 
��� ��������� ������ � ������� ����� �������� ���������
2) --create 
������� ��� �������� ��������� ������
3) --extract;
������� ��� ���������� �� ��������� ������ ������
4) --list 
������� ��� �������������� ������ ������, ���������� � ������

FILE1 FILE2 �. FILEN
��������� ��������� ��� �������� ������ ������ ��� ���������


������� �������������:
arc --file  data.arc --create a.txt b.bin c.bmp
arc --file  data.arc --extract
arc --file  data.arc --list

