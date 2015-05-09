-module (geometry).
-export ([area/1, circumference/1]).
area({rectangle, Width, Ht})	-> Width * Ht;
area({circle, R})				-> 3.14159 * R * R;
area({right_triangle, Left, Right})	-> Left * Right / 2.

circumference({rectangle, Width, Ht})	-> (Width + Ht) * 2;
circumference({circle, R})				-> 2 * 3.14159 * R;
circumference({right_triangle, Left, Right})	
	-> Left + Right + math:sqrt(Left * Left + Right * Right).