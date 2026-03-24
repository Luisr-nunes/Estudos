"""
Python Data Processor and Analyzer

This script simulates reading a CSV of financial transactions, cleaning the data,
and calculating basic moving averages and cumulative sums.
It is designed to demonstrate data manipulation skills without requiring external files.
"""

import random
from datetime import datetime, timedelta
import collections

# --- Step 1: Data Generation (Simulating a CSV structure) ---
def generate_test_data(rows=50):
    """Generates a list of dictionaries simulating CSV rows."""
    categories = ['Food', 'Transport', 'Utilities', 'Leisure', 'Savings']
    data = []
    base_date = datetime.now()
    
    for i in range(rows):
        transaction_date = base_date - timedelta(days=i)
        
        # Introduce some missing data to clean later
        amount = round(random.uniform(5.0, 150.0), 2) if random.random() > 0.1 else None
        
        data.append({
            'date': transaction_date.strftime('%Y-%m-%d'),
            'category': random.choice(categories),
            'amount': amount,
            'description': f'Transaction {i + 1}'
        })
    return data

# --- Step 2: Data Cleaning ---
def clean_and_format_data(raw_data):
    """Cleans missing data and formats currencies."""
    cleaned_data = []
    for row in raw_data:
        # Ignore rows with missing amounts
        if row['amount'] is not None:
            formatted_row = row.copy()
            # Ensure proper currency formatting (simulated)
            formatted_row['amount_formatted'] = f"${row['amount']:,.2f}"
            cleaned_data.append(formatted_row)
    return cleaned_data

# --- Step 3: Analysis ---
def calculate_moving_average(data, window=7):
    """Calculates a moving average on the 'amount' field."""
    amounts = [row['amount'] for row in data]
    results = []
    for i in range(len(amounts)):
        if i < window - 1:
            results.append(None) # Not enough data for average
        else:
            current_window = amounts[i - (window - 1) : i + 1]
            avg = sum(current_window) / window
            results.append(round(avg, 2))
    return results

def get_category_totals(data):
    """Totals the spending per category."""
    totals = collections.defaultdict(float)
    for row in data:
        totals[row['category']] += row['amount']
    return dict(totals)

# --- Step 4: Output Execution ---
def run_analysis_pipeline():
    print("--- 1. Generating Raw Data ---")
    raw_csv_data = generate_test_data()
    print(f"Total raw rows generated: {len(raw_csv_data)}")
    # Showing missing data simulation
    print(f"Sample raw data (one row): {raw_csv_data[0]}\n")

    print("--- 2. Cleaning Data ---")
    processed_data = clean_and_format_data(raw_csv_data)
    print(f"Total processed rows (after cleaning): {len(processed_data)}")
    print(f"Sample processed data: {processed_data[0]}\n")

    print("--- 3. Analyzing Data ---")
    
    # Calculate category spending
    category_spending = get_category_totals(processed_data)
    print("Total Spending by Category:")
    for cat, total in category_spending.items():
        print(f" - {cat: <10}: ${total:,.2f}")
    
    # Calculate moving average
    ma_7d = calculate_moving_average(processed_data, window=7)
    
    print("\nSample 7-Day Moving Average (last 5 rows with data):")
    # Show last 5 rows where a moving average was calculated
    show_count = 0
    for i in range(len(ma_7d)-1, -1, -1):
        if ma_7d[i] is not None:
            date = processed_data[i]['date']
            print(f" - Date: {date}, Avg: ${ma_7d[i]:,.2f}")
            show_count += 1
            if show_count >= 5:
                break
                
    print("\n--- Pipeline Execution Complete ---")

if __name__ == "__main__":
    run_analysis_pipeline()
