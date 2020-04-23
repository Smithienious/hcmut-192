hold on;
grid on;
rotate3d on;
xlim([0 3]);
ylim([0 3]);
zlim([0 2.5]);

xlabel('x');
ylabel('y');
zlabel('z');

x1 = [0 0 1];
y1 = [0 0 0.5];
z1 = [2 0 0];

x2 = [0 1 0];
y2 = [0 0.5 1];
z2 = [2 0 0];

x3 = [0 1 0];
y3 = [0 0.5 1];
z3 = [0 0 0];

x4 = [0 0 0];
y4 = [0 0 1];
z4 = [2 0 0];

fill3(x1, y1, z1, 'c');
fill3(x2, y2, z2, 'c');
fill3(x3, y3, z3, 'c');
fill3(x4, y4, z4, 'c');

hold off;