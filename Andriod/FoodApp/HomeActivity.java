package com.example.foodapp;

import android.os.Bundle;
import android.content.Intent;
import android.widget.*;

import androidx.appcompat.app.AppCompatActivity;

public class HomeActivity extends AppCompatActivity {

    Spinner spinner1, spinner2;
    TextView price1, price2, grandTotal;
    Button addCart;
    Button history;

    int burgerPrice = 120;
    int pizzaPrice = 200;

    int q1 = 0, q2 = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);

        spinner1 = findViewById(R.id.spinner1);
        spinner2 = findViewById(R.id.spinner2);

        price1 = findViewById(R.id.price1);
        price2 = findViewById(R.id.price2);
        grandTotal = findViewById(R.id.grandTotal);

        addCart = findViewById(R.id.addCart);

        Integer arr[] = {0, 1, 2, 3, 4, 5};

        ArrayAdapter<Integer> adapter = new ArrayAdapter<>(
                this,
                android.R.layout.simple_spinner_item,
                arr
        );

        adapter.setDropDownViewResource(
                android.R.layout.simple_spinner_dropdown_item
        );

        spinner1.setAdapter(adapter);
        spinner2.setAdapter(adapter);

        spinner1.setOnItemSelectedListener(new android.widget.AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(android.widget.AdapterView<?> parent,
                                       android.view.View view,
                                       int position, long id) {

                q1 = arr[position];
                calculatePrice();
            }

            @Override
            public void onNothingSelected(android.widget.AdapterView<?> parent) {}
        });

        spinner2.setOnItemSelectedListener(new android.widget.AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(android.widget.AdapterView<?> parent,
                                       android.view.View view,
                                       int position, long id) {

                q2 = arr[position];
                calculatePrice();
            }

            @Override
            public void onNothingSelected(android.widget.AdapterView<?> parent) {}
        });

        addCart.setOnClickListener(v -> {

            if (q1 == 0 && q2 == 0) {
                Toast.makeText(this, "Select a product", Toast.LENGTH_SHORT).show();
                return;
            }

            Intent i = new Intent(HomeActivity.this, CartActivity.class);

            i.putExtra("q1", q1);
            i.putExtra("q2", q2);

            startActivity(i);
        });

        history = findViewById(R.id.history);

        history.setOnClickListener(v -> {

            Intent i = new Intent(HomeActivity.this, HistoryActivity.class);

            startActivity(i);

        });
    }

    void calculatePrice() {

        int p1 = q1 * burgerPrice;
        int p2 = q2 * pizzaPrice;

        price1.setText("Total: ₹" + p1);
        price2.setText("Total: ₹" + p2);

        grandTotal.setText("Grand Total: ₹" + (p1 + p2));
    }
}
