package BasicTaskManager;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
 * Java Basic Task Manager
 *
 * This simple application simulates a task management system.
 * It demonstrates Core Java concepts: Objects, Classes, Lists,
 * the Strategy Pattern for command handling, and input processing.
 */

// 1. Task Model
class Task {
    private String title;
    private String description;
    private LocalDate dueDate;
    private boolean isCompleted;

    public Task(String title, String description, LocalDate dueDate) {
        this.title = title;
        this.description = description;
        this.dueDate = dueDate;
        this.isCompleted = false;
    }

    // Getters and Setters
    public String getTitle() { return title; }
    public String getDescription() { return description; }
    public LocalDate getDueDate() { return dueDate; }
    public boolean isCompleted() { return isCompleted; }

    @Override
    public String toString() {
        return " - [" + (isCompleted ? "X" : " ") + "] " +
               title + " (Due: " + dueDate + ") - " + description;
    }
}

// 2. TaskManager Repository
class TaskRepository {
    private List<Task> tasks;

    public TaskRepository() {
        this.tasks = new ArrayList<>();
    }

    public void addTask(Task task) {
        tasks.add(task);
    }

    public List<Task> getAllTasks() {
        return new ArrayList<>(tasks); // Return copy for encapsulation
    }
}

// 3. Command Strategy Interface
interface Command {
    void execute(TaskRepository repo, Scanner scanner);
}

// 4. Command Implementations
class AddTaskCommand implements Command {
    @Override
    public void execute(TaskRepository repo, Scanner scanner) {
        System.out.println("\n--- Add New Task ---");
        System.out.print("Enter Title: ");
        String title = scanner.nextLine();
        
        System.out.print("Enter Description: ");
        String description = scanner.nextLine();
        
        System.out.print("Enter Due Date (YYYY-MM-DD, e.g., 2024-12-31): ");
        String dateString = scanner.nextLine();
        LocalDate dueDate;
        try {
            dueDate = LocalDate.parse(dateString);
        } catch (Exception e) {
            System.out.println("Error: Invalid date format. Using today.");
            dueDate = LocalDate.now();
        }
        
        Task newTask = new Task(title, description, dueDate);
        repo.addTask(newTask);
        System.out.println("Task added successfully!\n");
    }
}

class ListTasksCommand implements Command {
    @Override
    public void execute(TaskRepository repo, Scanner scanner) {
        System.out.println("\n--- Task List ---");
        List<Task> tasks = repo.getAllTasks();
        if (tasks.isEmpty()) {
            System.out.println("No tasks found.");
        } else {
            for (int i = 0; i < tasks.size(); i++) {
                System.out.println((i + 1) + ". " + tasks.get(i));
            }
        }
        System.out.println();
    }
}

// 5. Main Application and CLI Loop
public class Main {
    public static void main(String[] args) {
        TaskRepository repository = new TaskRepository();
        Scanner scanner = new Scanner(System.in);
        boolean running = true;

        System.out.println("Welcome to the Simple Java Task Manager\n");

        while (running) {
            System.out.println("Available Commands:");
            System.out.println("1. Add Task");
            System.out.println("2. List Tasks");
            System.out.println("3. Exit");
            System.out.print("Enter your choice: ");

            String input = scanner.nextLine();
            
            Command command = null;
            switch (input) {
                case "1":
                    command = new AddTaskCommand();
                    break;
                case "2":
                    command = new ListTasksCommand();
                    break;
                case "3":
                    running = false;
                    System.out.println("\nExiting Task Manager...");
                    continue; // Skip command execution
                default:
                    System.out.println("\nInvalid choice. Please try again.\n");
                    continue;
            }
            
            if (command != null) {
                command.execute(repository, scanner);
            }
        }
        
        scanner.close();
    }
}
