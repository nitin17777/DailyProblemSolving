import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Random;

public class MainGame {
  private static final int WINDOW_WIDTH = 800;
  private static final int WINDOW_HEIGHT = 600;
  private JFrame frame;
  private CardLayout cardLayout;
  private JPanel mainPanel;

  public MainGame() {
    frame = new JFrame("Mini Games Collection");
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setResizable(false);

    cardLayout = new CardLayout();
    mainPanel = new JPanel(cardLayout);

    JPanel menuPanel = createMainMenu();
    mainPanel.add(menuPanel, "Menu");

    mainPanel.add(new WhackAMoleGame(this), "WhackAMole");
    mainPanel.add(new DodgerGame(this), "DodgerGame");
    mainPanel.add(new SnakeXenia(this), "SnakeXenia");
    mainPanel.add(new BrickBreakerGame1(this), "BrickBreaker");

    frame.add(mainPanel);
    frame.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    frame.setLocationRelativeTo(null);
    frame.setVisible(true);
    showMenu();
  }

  private JPanel createMainMenu() {
    JPanel menuPanel = new JPanel();
    menuPanel.setBackground(new Color(50, 50, 100));
    menuPanel.setLayout(new GridBagLayout());
    GridBagConstraints gbc = new GridBagConstraints();
    gbc.gridwidth = GridBagConstraints.REMAINDER;
    gbc.insets = new Insets(20, 0, 20, 0);

    JLabel titleLabel = new JLabel("Mini Games Collection");
    titleLabel.setFont(new Font("Arial", Font.BOLD, 40));
    titleLabel.setForeground(Color.WHITE);
    menuPanel.add(titleLabel, gbc);

    String[] gameNames = {"Whack-a-Mole", "Dodger Game", "Snake Xenia", "Brick Breaker"};
    String[] cardNames = {"WhackAMole", "DodgerGame", "SnakeXenia", "BrickBreaker"};
    for (int i = 0; i < gameNames.length; i++) {
      JButton button = new JButton(gameNames[i]);
      button.setFont(new Font("Arial", Font.PLAIN, 20));
      button.setPreferredSize(new Dimension(200, 50));
      final String cardName = cardNames[i];
      button.addActionListener(e -> {
        cardLayout.show(mainPanel, cardName);
        mainPanel.getComponent(mainPanel.getComponentCount()-1).requestFocusInWindow();
      });
      menuPanel.add(button, gbc);
    }
    return menuPanel;
  }

  public void showMenu() {
    cardLayout.show(mainPanel, "Menu");
    frame.requestFocus();
  }

  public static void main(String[] args) {
    SwingUtilities.invokeLater(MainGame::new);
  }
}

class WhackAMoleGame extends JPanel implements ActionListener, MouseListener {
  private static final int WIDTH = 600;
  private static final int HEIGHT = 400;
  private static final int GRID_SIZE = 50;
  private static final int MOLE_SIZE = 40;
  private static final int GAME_DURATION = 30000;
  private static final int MOLE_APPEARANCE_RATE = 500;
  private static final Color GRASS_COLOR = new Color(100, 200, 100);
  private static final Color DIRT_COLOR = new Color(150, 75, 0);
  private static final Font GAME_FONT = new Font("Arial", Font.BOLD, 20);
  private static final int GAME_DELAY = 30;

  private List<Point> moles = new ArrayList<>();
  private int score = 0;
  private boolean gameOver = false;
  private Timer timer;
  private Random random = new Random();
  private int timeRemaining;
  private int moleCounter = 0;
  private MainGame mainGame;

  public WhackAMoleGame(MainGame mainGame) {
    this.mainGame = mainGame;
    setPreferredSize(new Dimension(WIDTH, HEIGHT));
    setBackground(GRASS_COLOR);
    addMouseListener(this);
    setFocusable(true);
    requestFocusInWindow();

    addKeyListener(new KeyAdapter() {
      @Override
      public void keyPressed(KeyEvent e) {
        if (e.getKeyCode() == KeyEvent.VK_M) {
          timer.stop();
          mainGame.showMenu();
        }
      }
    });

    initGame();
  }

  private void initGame() {
    moles.clear();
    score = 0;
    gameOver = false;
    timeRemaining = GAME_DURATION;
    moleCounter = 0;

    if (timer != null) timer.stop();
    timer = new Timer(GAME_DELAY, this);
    timer.start();
  }

  @Override
  protected void paintComponent(Graphics g) {
    super.paintComponent(g);
    Graphics2D g2d = (Graphics2D) g;
    g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

    g.setColor(GRASS_COLOR);
    g.fillRect(0, 0, WIDTH, HEIGHT);

    drawDirtHoles(g);
    drawMoles(g);
    drawScoreAndTime(g);

    if (gameOver) {
      drawGameOver(g);
    }
  }

  private void drawDirtHoles(Graphics g) {
    g.setColor(DIRT_COLOR);
    for (int x = 0; x < WIDTH / GRID_SIZE; x++) {
      for (int y = 0; y < HEIGHT / GRID_SIZE; y++) {
        g.fillOval(x * GRID_SIZE + (GRID_SIZE - MOLE_SIZE) / 2,
          y * GRID_SIZE + (GRID_SIZE - MOLE_SIZE) / 2,
          MOLE_SIZE, MOLE_SIZE);
      }
    }
  }

  private void drawMoles(Graphics g) {
    for (Point mole : moles) {
      g.setColor(Color.getHSBColor(random.nextFloat(), 1.0f, 1.0f));
      g.fillOval(mole.x * GRID_SIZE + (GRID_SIZE - MOLE_SIZE) / 2,
        mole.y * GRID_SIZE + (GRID_SIZE - MOLE_SIZE) / 2,
        MOLE_SIZE, MOLE_SIZE);
      g.setColor(Color.BLACK);
      g.drawOval(mole.x * GRID_SIZE + (GRID_SIZE - MOLE_SIZE) / 2,
        mole.y * GRID_SIZE + (GRID_SIZE - MOLE_SIZE) / 2,
        MOLE_SIZE, MOLE_SIZE);
    }
  }

  private void drawScoreAndTime(Graphics g) {
    g.setColor(Color.WHITE);
    g.setFont(GAME_FONT);
    g.drawString("Score: " + score, 10, 20);
    g.drawString("Time: " + timeRemaining / 1000, 10, 40);
  }

  private void drawGameOver(Graphics g) {
    g.setColor(Color.RED);
    g.setFont(new Font("Arial", Font.BOLD, 40));
    String gameOverText = "Game Over";
    FontMetrics metrics = g.getFontMetrics(g.getFont());
    int x = (WIDTH - metrics.stringWidth(gameOverText)) / 2;
    int y = HEIGHT / 2;
    g.drawString(gameOverText, x, y);

    g.setColor(Color.WHITE);
    g.setFont(GAME_FONT);
    String restartText = "Click to Restart or Press M for Menu";
    int restartX = (WIDTH - metrics.stringWidth(restartText)) / 2;
    int restartY = y + 30;
    g.drawString(restartText, restartX, restartY);
  }

  @Override
  public void actionPerformed(ActionEvent e) {
    if (gameOver) return;

    moleCounter += GAME_DELAY;
    if (moleCounter >= MOLE_APPEARANCE_RATE) {
      moleCounter = 0;
      addMole();
    }

    Iterator<Point> iterator = moles.iterator();
    while (iterator.hasNext()) {
      Point mole = iterator.next();
      mole.lifetime += GAME_DELAY;
      if (mole.lifetime > 1000) {
        iterator.remove();
      }
    }

    timeRemaining -= GAME_DELAY;
    if (timeRemaining <= 0) {
      gameOver = true;
      timer.stop();
    }
    repaint();
  }

  private void addMole() {
    int x = random.nextInt(WIDTH / GRID_SIZE);
    int y = random.nextInt(HEIGHT / GRID_SIZE);
    if (!isMolePresent(x, y)) {
      Point mole = new Point(x, y);
      mole.lifetime = 0;
      moles.add(mole);
    }
  }

  private boolean isMolePresent(int x, int y) {
    for (Point mole : moles) {
      if (mole.x == x && mole.y == y) {
        return true;
      }
    }
    return false;
  }

  @Override
  public void mouseClicked(MouseEvent e) {
    if (gameOver) {
      if (e.getButton() == MouseEvent.BUTTON1) {
        initGame();
      }
      return;
    }

    int x = e.getX();
    int y = e.getY();

    Iterator<Point> iterator = moles.iterator();
    while (iterator.hasNext()) {
      Point mole = iterator.next();
      int moleX = mole.x * GRID_SIZE + GRID_SIZE / 2;
      int moleY = mole.y * GRID_SIZE + GRID_SIZE / 2;
      int distance = (int) Math.sqrt(Math.pow(x - moleX, 2) + Math.pow(y - moleY, 2));
      if (distance <= MOLE_SIZE / 2) {
        iterator.remove();
        score++;
        break;
      }
    }
    repaint();
  }

  @Override public void mousePressed(MouseEvent e) {}
  @Override public void mouseReleased(MouseEvent e) {}
  @Override public void mouseEntered(MouseEvent e) {}
  @Override public void mouseExited(MouseEvent e) {}

  private static class Point extends java.awt.Point {
    int lifetime;
    public Point(int x, int y) {
      super(x, y);
      this.lifetime = 0;
    }
  }
}
/*class DodgerGame extends JPanel implements ActionListener, KeyListener {
  private static final int WIDTH = 800;
  private static final int HEIGHT = 600;
  private static final int GROUND_Y = 450;
  private static final int PLAYER_WIDTH = 50;
  private static final int PLAYER_HEIGHT = 70;
  private static final int OBSTACLE_WIDTH = 30;
  private static final int OBSTACLE_HEIGHT = 50;
  private static final int GAME_DELAY = 15;
  private static final int OBSTACLE_FREQUENCY = 1500; // milliseconds
  private static final Font GAME_FONT = new Font("Arial", Font.BOLD, 24);

  private int playerX = 100;
  private int playerY = GROUND_Y - PLAYER_HEIGHT;
  private int playerVelocityY = 0;
  private boolean isJumping = false;
  private boolean isDucking = false;
  private List<Rectangle> obstacles = new ArrayList<>();
  private int score = 0;
  private boolean gameOver = false;
  private boolean gameStarted = false;
  private Timer timer;
  private Random random = new Random();
  private int obstacleCounter = 0;
  private int gameSpeed = 5;
  private MainGame mainGame;
  private int jumpHeight = 20;
  private int gravity = 1;
  private int cloudPosition = 0;

  public DodgerGame(MainGame mainGame) {
    this.mainGame = mainGame;
    setPreferredSize(new Dimension(WIDTH, HEIGHT));
    setBackground(Color.WHITE);
    addKeyListener(this);
    setFocusable(true);
    requestFocusInWindow();
    initGame();
  }

  private void initGame() {
    playerX = 100;
    playerY = GROUND_Y - PLAYER_HEIGHT;
    playerVelocityY = 0;
    isJumping = false;
    isDucking = false;
    obstacles.clear();
    score = 0;
    gameOver = false;
    gameStarted = false;
    gameSpeed = 5;
    cloudPosition = 0;

    if (timer != null) {
      timer.stop();
    }
    timer = new Timer(GAME_DELAY, this);
  }

  @Override
  protected void paintComponent(Graphics g) {
    super.paintComponent(g);
    Graphics2D g2d = (Graphics2D) g;
    g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

    // Draw sky
    g2d.setColor(new Color(135, 206, 235));
    g2d.fillRect(0, 0, WIDTH, HEIGHT);

    // Draw clouds
    drawClouds(g2d);

    // Draw ground
    g2d.setColor(new Color(83, 49, 24));
    g2d.fillRect(0, GROUND_Y, WIDTH, 2);
    g2d.setColor(new Color(210, 180, 140));
    g2d.fillRect(0, GROUND_Y + 2, WIDTH, HEIGHT - GROUND_Y - 2);

    // Draw player (dinosaur)
    if (isDucking) {
      drawDuckingPlayer(g2d);
    } else {
      drawStandingPlayer(g2d);
    }

    // Draw obstacles (cacti)
    drawObstacles(g2d);

    // Draw score
    g2d.setColor(Color.BLACK);
    g2d.setFont(GAME_FONT);
    g2d.drawString("Score: " + score, 20, 30);

    // Draw appropriate message
    if (!gameStarted) {
      drawStartMessage(g2d);
    } else if (gameOver) {
      drawGameOver(g2d);
    }
  }

  private void drawClouds(Graphics2D g2d) {
    g2d.setColor(new Color(255, 255, 255, 200));
    int[] cloudX = {200, 500, 800};
    for (int i = 0; i < cloudX.length; i++) {
      int x = (cloudX[i] - cloudPosition) % WIDTH;
      if (x < 0) x += WIDTH;
      int y = 50 + (i * 40) % 100;
      g2d.fillOval(x, y, 80, 40);
      g2d.fillOval(x + 20, y - 10, 40, 40);
      g2d.fillOval(x + 40, y, 60, 30);
    }
  }

  private void drawStandingPlayer(Graphics2D g2d) {
    // Body
    g2d.setColor(new Color(100, 100, 100));
    g2d.fillRect(playerX, playerY, PLAYER_WIDTH, PLAYER_HEIGHT);

    // Head
    g2d.fillRect(playerX + 5, playerY - 20, PLAYER_WIDTH - 10, 25);

    // Eye
    g2d.setColor(Color.WHITE);
    g2d.fillOval(playerX + 35, playerY - 15, 10, 10);
    g2d.setColor(Color.BLACK);
    g2d.fillOval(playerX + 38, playerY - 12, 4, 4);

    // Legs
    if ((score / 10) % 2 == 0) {
      g2d.setColor(new Color(80, 80, 80));
      g2d.fillRect(playerX + 10, playerY + PLAYER_HEIGHT, 12, 15);
      g2d.fillRect(playerX + 30, playerY + PLAYER_HEIGHT - 8, 12, 23);
    } else {
      g2d.setColor(new Color(80, 80, 80));
      g2d.fillRect(playerX + 10, playerY + PLAYER_HEIGHT - 8, 12, 23);
      g2d.fillRect(playerX + 30, playerY + PLAYER_HEIGHT, 12, 15);
    }
  }

  private void drawDuckingPlayer(Graphics2D g2d) {
    int duckHeight = PLAYER_HEIGHT / 2;

    // Body when ducking
    g2d.setColor(new Color(100, 100, 100));
    g2d.fillRect(playerX, playerY + PLAYER_HEIGHT - duckHeight, PLAYER_WIDTH + 15, duckHeight);

    // Head when ducking
    g2d.fillRect(playerX + 15, playerY + PLAYER_HEIGHT - duckHeight - 15, PLAYER_WIDTH, 15);

    // Eye when ducking
    g2d.setColor(Color.WHITE);
    g2d.fillOval(playerX + 50, playerY + PLAYER_HEIGHT - duckHeight - 10, 8, 8);
    g2d.setColor(Color.BLACK);
    g2d.fillOval(playerX + 53, playerY + PLAYER_HEIGHT - duckHeight - 8, 3, 3);

    // Legs when ducking
    if ((score / 10) % 2 == 0) {
      g2d.setColor(new Color(80, 80, 80));
      g2d.fillRect(playerX + 10, playerY + PLAYER_HEIGHT, 12, 15);
      g2d.fillRect(playerX + 40, playerY + PLAYER_HEIGHT, 12, 15);
    } else {
      g2d.setColor(new Color(80, 80, 80));
      g2d.fillRect(playerX + 25, playerY + PLAYER_HEIGHT, 12, 15);
      g2d.fillRect(playerX + 55, playerY + PLAYER_HEIGHT, 12, 15);
    }
  }

  private void drawObstacles(Graphics2D g2d) {
    g2d.setColor(new Color(0, 100, 0));
    for (Rectangle obstacle : obstacles) {
      // Draw a cactus
      int baseX = obstacle.x;
      int baseY = obstacle.y;
      int width = obstacle.width;
      int height = obstacle.height;

      // Main stem
      g2d.fillRect(baseX + width/3, baseY - height, width/3, height);

      // Arms
      if (height > 35) {
        // Left arm
        g2d.fillRect(baseX, baseY - height + height/3, width/3, width/3);
        g2d.fillRect(baseX, baseY - height + height/3, width/3, height/3);

        // Right arm
        g2d.fillRect(baseX + 2*width/3, baseY - height + height/2, width/3, width/3);
        g2d.fillRect(baseX + 2*width/3, baseY - height + height/2, width/3, height/3);
      }
    }
  }

  private void drawStartMessage(Graphics2D g2d) {
    g2d.setColor(new Color(0, 0, 0, 150));
    g2d.fillRect(0, 0, WIDTH, HEIGHT);

    g2d.setColor(Color.WHITE);
    g2d.setFont(new Font("Arial", Font.BOLD, 40));
    String message = "Dodger Game";
    int x = (WIDTH - g2d.getFontMetrics().stringWidth(message)) / 2;
    g2d.drawString(message, x, HEIGHT/2 - 50);

    g2d.setFont(new Font("Arial", Font.PLAIN, 24));
    message = "Press SPACE to Start";
    x = (WIDTH - g2d.getFontMetrics().stringWidth(message)) / 2;
    g2d.drawString(message, x, HEIGHT/2 + 20);
  }

  private void drawGameOver(Graphics2D g2d) {
    g2d.setColor(new Color(0, 0, 0, 150));
    g2d.fillRect(0, 0, WIDTH, HEIGHT);

    g2d.setColor(Color.RED);
    g2d.setFont(new Font("Arial", Font.BOLD, 40));
    String message = "Game Over!";
    int x = (WIDTH - g2d.getFontMetrics().stringWidth(message)) / 2;
    g2d.drawString(message, x, HEIGHT/2 - 50);

    g2d.setColor(Color.WHITE);
    g2d.setFont(new Font("Arial", Font.PLAIN, 24));
    message = "Final Score: " + score;
    x = (WIDTH - g2d.getFontMetrics().stringWidth(message)) / 2;
    g2d.drawString(message, x, HEIGHT/2);

    message = "Press SPACE to Restart or M for Menu";
    x = (WIDTH - g2d.getFontMetrics().stringWidth(message)) / 2;
    g2d.drawString(message, x, HEIGHT/2 + 50);
  }

  @Override
  public void actionPerformed(ActionEvent e) {
    if (!gameStarted || gameOver) return;

    // Update score
    score++;
    if (score % 500 == 0) {
      gameSpeed++;
    }

    // Move clouds
    cloudPosition += Math.max(1, gameSpeed / 3);

    // Apply gravity to player when jumping
    if (isJumping) {
      playerY += playerVelocityY;
      playerVelocityY += gravity;

      if (playerY >= GROUND_Y - PLAYER_HEIGHT) {
        playerY = GROUND_Y - PLAYER_HEIGHT;
        isJumping = false;
        playerVelocityY = 0;
      }
    }

    // Move obstacles and check collisions
    Iterator<Rectangle> iterator = obstacles.iterator();
    while (iterator.hasNext()) {
      Rectangle obstacle = iterator.next();
      obstacle.x -= gameSpeed;

      if (obstacle.x + obstacle.width < 0) {
        iterator.remove();
      }

      // Create player hitbox
      Rectangle playerRect;
      if (isDucking) {
        playerRect = new Rectangle(playerX, playerY + PLAYER_HEIGHT / 2,
          PLAYER_WIDTH + 15, PLAYER_HEIGHT / 2);
      } else {
        playerRect = new Rectangle(playerX, playerY, PLAYER_WIDTH, PLAYER_HEIGHT);
      }

      // Check collision with obstacle
      Rectangle obstacleHitbox = new Rectangle(obstacle.x + obstacle.width/3,
        obstacle.y - obstacle.height,
        obstacle.width/3, obstacle.height);
      if (playerRect.intersects(obstacleHitbox)) {
        gameOver = true;
        timer.stop();
        repaint();
        return;
      }
    }

    // Add new obstacles
    obstacleCounter += GAME_DELAY;
    if (obstacleCounter >= OBSTACLE_FREQUENCY - (gameSpeed * 50)) {
      obstacleCounter = 0;
      addObstacle();
    }

    repaint();
  }

  private void addObstacle() {
    int height = random.nextInt(30) + 30; // Random height between 30 and 60
    obstacles.add(new Rectangle(WIDTH, GROUND_Y, OBSTACLE_WIDTH, height));
  }

  @Override
  public void keyPressed(KeyEvent e) {
    int key = e.getKeyCode();

    if (key == KeyEvent.VK_SPACE) {
      if (!gameStarted && !gameOver) {
        gameStarted = true;
        timer.start();
      } else if (gameOver) {
        initGame();
        gameStarted = true;
        timer.start();
      } else if (!isJumping) {
        isJumping = true;
        playerVelocityY = -jumpHeight;
      }
    }

    if (key == KeyEvent.VK_DOWN || key == KeyEvent.VK_S) {
      isDucking = true;
    }

    if (key == KeyEvent.VK_M) {
      timer.stop();
      mainGame.showMenu();
    }
  }

  @Override
  public void keyReleased(KeyEvent e) {
    int key = e.getKeyCode();
    if (key == KeyEvent.VK_DOWN || key == KeyEvent.VK_S) {
      isDucking = false;
    }
  }

  @Override
  public void keyTyped(KeyEvent e) {}
} */
// Modified Snake Xenia
class SnakeXenia extends JPanel implements ActionListener, KeyListener {
  private static final int GRID_SIZE = 20;
  private static final int WIDTH = 600;
  private static final int HEIGHT = 400;
  private static final int DELAY = 150;
  private static final Font GAME_FONT = new Font("Arial", Font.BOLD, 20);

  private ArrayList<Point> snake;
  private Point food;
  private Direction direction;
  private Direction nextDirection;
  private boolean running = false;
  private boolean gameStarted = false;
  private Timer timer;
  private Random random;
  private int score;
  private MainGame mainGame;

  public SnakeXenia(MainGame mainGame) {
    this.mainGame = mainGame;
    setPreferredSize(new Dimension(WIDTH, HEIGHT));
    setBackground(Color.BLACK);
    addKeyListener(this);
    setFocusable(true);
    requestFocusInWindow();
    random = new Random();
    initGame();
  }

  private void initGame() {
    snake = new ArrayList<>();
    snake.add(new Point(GRID_SIZE * 5, GRID_SIZE * 5));
    direction = Direction.RIGHT;
    nextDirection = Direction.RIGHT;
    food = createFood();
    running = true;
    gameStarted = false;
    score = 0;

    if (timer != null) {
      timer.stop();
    }
    timer = new Timer(DELAY, this);
  }

  private Point createFood() {
    int x, y;
    boolean onSnake;
    do {
      onSnake = false;
      x = random.nextInt(WIDTH / GRID_SIZE) * GRID_SIZE;
      y = random.nextInt(HEIGHT / GRID_SIZE) * GRID_SIZE;

      for (Point segment : snake) {
        if (segment.x == x && segment.y == y) {
          onSnake = true;
          break;
        }
      }
    } while (onSnake);

    return new Point(x, y);
  }

  @Override
  public void actionPerformed(ActionEvent e) {
    if (!gameStarted || !running) return;

    direction = nextDirection;
    move();
    checkCollision();
    checkFood();
    repaint();
  }

  private void move() {
    Point head = new Point(snake.get(0));

    switch (direction) {
      case UP:
        head.y -= GRID_SIZE;
        break;
      case DOWN:
        head.y += GRID_SIZE;
        break;
      case LEFT:
        head.x -= GRID_SIZE;
        break;
      case RIGHT:
        head.x += GRID_SIZE;
        break;
    }

    snake.add(0, head);
    snake.remove(snake.size() - 1);
  }

  private void checkFood() {
    if (snake.get(0).equals(food)) {
      score++;
      snake.add(new Point(snake.get(snake.size() - 1)));
      food = createFood();
    }
  }

  private void checkCollision() {
    Point head = snake.get(0);

    // Wall collision
    if (head.x < 0 || head.x >= WIDTH || head.y < 0 || head.y >= HEIGHT) {
      running = false;
      timer.stop();
      return;
    }

    // Self collision
    for (int i = 1; i < snake.size(); i++) {
      if (head.equals(snake.get(i))) {
        running = false;
        timer.stop();
        return;
      }
    }
  }

  @Override
  protected void paintComponent(Graphics g) {
    super.paintComponent(g);
    draw(g);
  }

  private void draw(Graphics g) {
    Graphics2D g2d = (Graphics2D)g;
    g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

    // Draw food
    g2d.setColor(Color.RED);
    g2d.fillOval(food.x, food.y, GRID_SIZE, GRID_SIZE);

    // Draw snake
    for (int i = 0; i < snake.size(); i++) {
      if (i == 0) {
        g2d.setColor(Color.GREEN);
      } else {
        g2d.setColor(new Color(45, 180, 0));
      }
      g2d.fillRect(snake.get(i).x, snake.get(i).y, GRID_SIZE, GRID_SIZE);
      g2d.setColor(Color.BLACK);
      g2d.drawRect(snake.get(i).x, snake.get(i).y, GRID_SIZE, GRID_SIZE);
    }

    // Draw score
    g2d.setColor(Color.WHITE);
    g2d.setFont(GAME_FONT);
    g2d.drawString("Score: " + score, 10, 20);

    if (!gameStarted) {
      drawCenteredMessage(g2d, "Press SPACE to Start", 30, Color.WHITE);
    } else if (!running) {
      drawCenteredMessage(g2d, "GAME OVER", 40, Color.RED);
      drawCenteredMessage(g2d, "Final Score: " + score, 30, Color.WHITE);
      drawCenteredMessage(g2d, "Press SPACE to Restart", 25, Color.YELLOW);
      drawCenteredMessage(g2d, "Press M for Menu", 25, Color.YELLOW);
    }
  }

  private void drawCenteredMessage(Graphics g, String text, int size, Color color) {
    g.setFont(new Font("Arial", Font.BOLD, size));
    FontMetrics metrics = g.getFontMetrics();
    int x = (WIDTH - metrics.stringWidth(text)) / 2;
    int y = HEIGHT / 2 + (size * 2) * (g.getFont().getSize() / 10);
    g.setColor(new Color(0, 0, 0, 150));
    g.drawString(text, x + 2, y + 2);
    g.setColor(color);
    g.drawString(text, x, y);
  }

  @Override
  public void keyPressed(KeyEvent e) {
    int key = e.getKeyCode();

    if (key == KeyEvent.VK_M) {
      timer.stop();
      mainGame.showMenu();
      return;
    }

    if (!gameStarted && key == KeyEvent.VK_SPACE) {
      gameStarted = true;
      timer.start();
      return;
    }

    if (!running && key == KeyEvent.VK_SPACE) {
      initGame();
      gameStarted = true;
      timer.start();
      return;
    }

    if (gameStarted && running) {
      switch (key) {
        case KeyEvent.VK_UP:
          if (direction != Direction.DOWN) nextDirection = Direction.UP;
          break;
        case KeyEvent.VK_DOWN:
          if (direction != Direction.UP) nextDirection = Direction.DOWN;
          break;
        case KeyEvent.VK_LEFT:
          if (direction != Direction.RIGHT) nextDirection = Direction.LEFT;
          break;
        case KeyEvent.VK_RIGHT:
          if (direction != Direction.LEFT) nextDirection = Direction.RIGHT;
          break;
      }
    }
  }

  @Override public void keyTyped(KeyEvent e) {}
  @Override public void keyReleased(KeyEvent e) {}

  private enum Direction {
    UP, DOWN, LEFT, RIGHT
  }
}

// Modified Brick Breaker Game
class BrickBreakerGame1 extends JPanel implements ActionListener, KeyListener {
  private static final int WIDTH = 800;
  private static final int HEIGHT = 600;
  private static final int PADDLE_WIDTH = 120;
  private static final int PADDLE_HEIGHT = 15;
  private static final int BALL_DIAMETER = 20;
  private static final int BRICK_WIDTH = 70;
  private static final int BRICK_HEIGHT = 25;
  private static final int BRICK_ROWS = 5;
  private static final int BRICK_COLS = 10;
  private static final int DELAY = 10;

  private int paddleX;
  private int ballX, ballY;
  private int ballSpeedX = 3;
  private int ballSpeedY = -3;
  private boolean gameRunning;
  private int score;
  private int lives = 5;
  private int paddleSpeed = 20;
  private int currentSpeedLevel = 1;
  private int[] speedLevelThresholds = {0, 150, 300, 450, 600};
  private Color[] speedColors = {
    new Color(100, 255, 100), new Color(100, 200, 255), new Color(255, 200, 100),
    new Color(255, 100, 100), new Color(255, 100, 255)
  };
  private ArrayList<Brick> bricks;
  private Timer timer;
  private MainGame mainGame;

  public BrickBreakerGame1(MainGame mainGame) {
    this.mainGame = mainGame;
    setPreferredSize(new Dimension(WIDTH, HEIGHT));
    setBackground(new Color(20, 20, 40));
    addKeyListener(this);
    setFocusable(true);
    setFocusTraversalKeysEnabled(false);
    initGame();
  }

  private void initGame() {
    paddleX = (WIDTH - PADDLE_WIDTH) / 2;
    ballX = WIDTH / 2 - BALL_DIAMETER / 2;
    ballY = HEIGHT - 100;
    Random rand = new Random();
    ballSpeedX = rand.nextBoolean() ? 3 : -3;
    ballSpeedY = -3;
    gameRunning = false;
    score = 0;
    lives = 5;
    currentSpeedLevel = 1;
    createBricks();
    timer = new Timer(DELAY, this);
    timer.start();
  }

  private void createBricks() {
    bricks = new ArrayList<>();
    int totalBricksWidth = BRICK_COLS * BRICK_WIDTH;
    int startX = (WIDTH - totalBricksWidth) / 2;
    Color[] rowColors = {
      new Color(255, 100, 100), new Color(255, 180, 100), new Color(255, 255, 100),
      new Color(180, 255, 100), new Color(100, 255, 180)
    };
    for (int i = 0; i < rowColors.length; i++) {
      rowColors[i] = rowColors[i].brighter();
    }
    for (int row = 0; row < BRICK_ROWS; row++) {
      for (int col = 0; col < BRICK_COLS; col++) {
        int brickX = startX + col * BRICK_WIDTH;
        int brickY = 50 + row * BRICK_HEIGHT;
        Color baseColor = rowColors[row];
        int variation = (col % 3) * 20;
        Color brickColor = new Color(
          Math.min(255, baseColor.getRed() + variation),
          Math.min(255, baseColor.getGreen() + variation),
          Math.min(255, baseColor.getBlue() + variation)
        );
        bricks.add(new Brick(brickX, brickY, BRICK_WIDTH, BRICK_HEIGHT, brickColor));
      }
    }
  }

  private void updateSpeedLevel() {
    for (int i = speedLevelThresholds.length - 1; i >= 0; i--) {
      if (score >= speedLevelThresholds[i]) {
        currentSpeedLevel = i + 1;
        break;
      }
    }
    int speedIncrease = currentSpeedLevel - 1;
    if (ballSpeedX > 0) ballSpeedX = 3 + speedIncrease;
    if (ballSpeedX < 0) ballSpeedX = -3 - speedIncrease;
    if (ballSpeedY > 0) ballSpeedY = 3 + speedIncrease;
    if (ballSpeedY < 0) ballSpeedY = -3 - speedIncrease;
  }

  @Override
  protected void paintComponent(Graphics g) {
    super.paintComponent(g);
    Graphics2D g2d = (Graphics2D) g;
    Color color1 = new Color(20, 20, 40);
    Color color2 = new Color(10, 10, 25);
    GradientPaint gp = new GradientPaint(0, 0, color1, 0, HEIGHT, color2);
    g2d.setPaint(gp);
    g2d.fillRect(0, 0, WIDTH, HEIGHT);

    Color paddleColor = speedColors[Math.min(currentSpeedLevel - 1, speedColors.length - 1)];
    g.setColor(paddleColor);
    g.fillRoundRect(paddleX, HEIGHT - 50, PADDLE_WIDTH, PADDLE_HEIGHT, 10, 10);
    g.setColor(paddleColor.brighter());
    g.drawRoundRect(paddleX, HEIGHT - 50, PADDLE_WIDTH, PADDLE_HEIGHT, 10, 10);

    g.setColor(Color.WHITE);
    g.fillOval(ballX, ballY, BALL_DIAMETER, BALL_DIAMETER);
    g.setColor(new Color(255, 255, 255, 100));
    g.fillOval(ballX - 2, ballY - 2, BALL_DIAMETER + 4, BALL_DIAMETER + 4);

    for (Brick brick : bricks) {
      g.setColor(brick.color);
      g.fillRoundRect(brick.rect.x, brick.rect.y, brick.rect.width, brick.rect.height, 5, 5);
      g.setColor(brick.color.brighter());
      g.drawRoundRect(brick.rect.x, brick.rect.y, brick.rect.width, brick.rect.height, 5, 5);
      g.setColor(brick.color.darker());
      g.drawRoundRect(brick.rect.x + 1, brick.rect.y + 1, brick.rect.width - 2, brick.rect.height - 2, 5, 5);
    }

    g.setColor(new Color(255, 255, 255, 200));
    g.setFont(new Font("Arial", Font.BOLD, 20));
    g.drawString("★ " + score, 20, 30);
    String hearts = "❤ ".repeat(Math.max(0, lives));
    g.drawString(hearts, WIDTH - 100, 30);
    Color speedColor = speedColors[Math.min(currentSpeedLevel - 1, speedColors.length - 1)];
    g.setColor(speedColor);
    g.drawString("⚡ " + currentSpeedLevel, WIDTH / 2 - 20, 30);

    if (!gameRunning && lives > 0 && !bricks.isEmpty()) {
      g.setFont(new Font("Arial", Font.BOLD, 30));
      g.setColor(new Color(255, 255, 255, 200));
      g.drawString("Press SPACE to Start", WIDTH / 2 - 148, HEIGHT / 2 + 3);
      g.setColor(new Color(100, 200, 255));
      g.drawString("Press SPACE to Start", WIDTH / 2 - 150, HEIGHT / 2);
    }

    if (lives <= 0) {
      drawCenteredMessage(g, "GAME OVER", 40, new Color(255, 100, 100));
      drawCenteredMessage(g, "Final Score: " + score, 20, Color.WHITE);
      drawCenteredMessage(g, "Press R to Restart or M for Menu", 20, new Color(200, 200, 255));
    }

    if (bricks.isEmpty()) {
      drawCenteredMessage(g, "LEVEL COMPLETE!", 40, new Color(100, 255, 100));
      drawCenteredMessage(g, "Score: " + score, 20, Color.WHITE);
      drawCenteredMessage(g, "Press R for Next Level or M for Menu", 20, new Color(200, 200, 255));
    }
  }

  private void drawCenteredMessage(Graphics g, String text, int size, Color color) {
    g.setFont(new Font("Arial", Font.BOLD, size));
    FontMetrics fm = g.getFontMetrics();
    int x = (WIDTH - fm.stringWidth(text)) / 2;
    g.setColor(new Color(0, 0, 0, 150));
    g.drawString(text, x + 2, HEIGHT / 2 + 2);
    g.setColor(color);
    g.drawString(text, x, HEIGHT / 2);
  }

  @Override
  public void actionPerformed(ActionEvent e) {
    if (gameRunning) {
      ballX += ballSpeedX;
      ballY += ballSpeedY;

      if (ballX <= 0 || ballX + BALL_DIAMETER >= WIDTH) {
        ballSpeedX = -ballSpeedX;
      }
      if (ballY <= 0) {
        ballSpeedY = -ballSpeedY;
      }
      if (ballY + BALL_DIAMETER >= HEIGHT) {
        gameRunning = false;
        lives--;
        if (lives > 0) {
          initBallAndPaddle();
          gameRunning = true;
        }
      }

      Rectangle ballRect = new Rectangle(ballX, ballY, BALL_DIAMETER, BALL_DIAMETER);
      Rectangle paddleRect = new Rectangle(paddleX, HEIGHT - 50, PADDLE_WIDTH, PADDLE_HEIGHT);
      if (ballRect.intersects(paddleRect)) {
        ballSpeedY = -ballSpeedY;
        int paddleCenter = paddleX + PADDLE_WIDTH / 2;
        int hitPosition = ballX + BALL_DIAMETER / 2;
        int deflection = (hitPosition - paddleCenter) / (PADDLE_WIDTH / 10);
        ballSpeedX += deflection;
        ballSpeedX = Math.max(-10, Math.min(10, ballSpeedX));
      }

      ArrayList<Brick> bricksToRemove = new ArrayList<>();
      for (Brick brick : bricks) {
        if (ballRect.intersects(brick.rect)) {
          Rectangle brickRect = brick.rect;
          if (ballY + BALL_DIAMETER > brickRect.y && ballY < brickRect.y + brickRect.height) {
            ballSpeedY = -ballSpeedY;
          } else {
            ballSpeedX = -ballSpeedX;
          }
          bricksToRemove.add(brick);
          score += 10;
          updateSpeedLevel();
          break;
        }
      }
      bricks.removeAll(bricksToRemove);

      repaint();
    }
  }

  private void initBallAndPaddle() {
    paddleX = (WIDTH - PADDLE_WIDTH) / 2;
    ballX = WIDTH / 2 - BALL_DIAMETER / 2;
    ballY = HEIGHT - 100;
    Random rand = new Random();
    ballSpeedX = rand.nextBoolean() ? 3 : -3;
    ballSpeedY = -3;
  }

  @Override
  public void keyPressed(KeyEvent e) {
    if (gameRunning) {
      if (e.getKeyCode() == KeyEvent.VK_LEFT) {
        paddleX -= paddleSpeed;
        if (paddleX < 0) {
          paddleX = 0;
        }
      } else if (e.getKeyCode() == KeyEvent.VK_RIGHT) {
        paddleX += paddleSpeed;
        if (paddleX > WIDTH - PADDLE_WIDTH) {
          paddleX = WIDTH - PADDLE_WIDTH;
        }
      }
    } else {
      if (e.getKeyCode() == KeyEvent.VK_SPACE && lives > 0) {
        gameRunning = true;
      } else if (e.getKeyCode() == KeyEvent.VK_R) {
        if (lives <= 0 || bricks.isEmpty()) {
          initGame();
        }
      } else if (e.getKeyCode() == KeyEvent.VK_M) {
        timer.stop();
        mainGame.showMenu();
      }
    }
    repaint();
  }

  @Override
  public void keyTyped(KeyEvent e) {}
  @Override
  public void keyReleased(KeyEvent e) {}
}

// Brick class for BrickBreakerGame1
class Brick {
  Rectangle rect;
  Color color;

  public Brick(int x, int y, int width, int height, Color color) {
    this.rect = new Rectangle(x, y, width, height);
    this.color = color;
  }
}