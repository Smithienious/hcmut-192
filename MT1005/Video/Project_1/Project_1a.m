hold on;
grid on;
rotate3d on;
xlabel('x');
ylabel('y');
zlabel('z');

xlim([0 1.5]);
ylim([0 1.5]);
zlim([0 1.5]);

t = 0:0.01:1;

x1 = t;
y1 = sqrt(t);
z1 = zeros(1, 101);
x1 = [x1 0];
y1 = [y1 1];
z1 = [z1 0];

x2 = t;
y2 = sqrt(t);
z2 = 1 - sqrt(t);
x2 = [x2 0];
y2 = [y2 1];
z2 = [z2 0];

x3 = [0 0 0];
y3 = [0 1 0];
z3 = [0 0 1];

x4 = t;
y4 = sqrt(x4);
c1 = zeros(1, 101);
c2 = 1 - sqrt(x4);

curve1 = [x4; y4; c1];
curve2 = [x4; y4; c2];
X=[curve1(1, :), fliplr(curve2(1, :))];
Y=[curve1(2, :), fliplr(curve2(2, :))];
Z=[curve1(3, :), fliplr(curve2(3, :))];

fill3(x1, y1, z1, 'c');
fill3(x2, y2, z2, 'c');
fill3(x3, y3, z3, 'c');
fill3(X, Y, Z, 'c');

hold off;