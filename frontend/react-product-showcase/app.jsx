// React Product Showcase - Core Application Logic (JS/JSX)
// This file demonstrates React fundamentals: Functional Components, Hooks (useState, useEffect), 
// Event Handling, and dynamic list rendering.

const { useState, useEffect } = React;

// 1. Presentational Component: ProductCard
// Shows individual product details. Demonstrates Props usage.
const ProductCard = ({ product, onAddToCart }) => {
    return (
        <div class="bg-white p-6 rounded-xl shadow-md border border-gray-100 flex flex-col transition hover:shadow-lg">
            <div class="w-full h-40 bg-gray-100 rounded-lg mb-4 flex items-center justify-center text-gray-400 font-mono text-xs">
                Image Placeholder
            </div>
            <h3 class="text-lg font-semibold text-gray-900 mb-1">{product.name}</h3>
            <p class="text-sm text-gray-600 mb-4 flex-grow">{product.description}</p>
            
            <div class="flex items-center justify-between mt-auto pt-4 border-t border-gray-100">
                <span class="text-xl font-bold text-green-700">
                    ${product.price.toFixed(2)}
                </span>
                <button 
                    onClick={() => onAddToCart(product)}
                    class="bg-blue-600 hover:bg-blue-700 text-white px-4 py-2 rounded-lg text-sm font-semibold transition flex items-center gap-2"
                >
                    Add
                </button>
            </div>
        </div>
    );
};

// 2. Main Application Component: App
const App = () => {
    // State management for products, search term, and cart count
    const [products, setProducts] = useState([]);
    const [searchTerm, setSearchTerm] = useState('');
    const [cartCount, setCartCount] = useState(0);
    const [isLoading, setIsLoading] = useState(true);

    // useEffect hook to simulate fetching data from an API on component mount
    useEffect(() => {
        // Simulating a network delay
        const timer = setTimeout(() => {
            const mockProducts = [
                { id: 1, name: "Wireless Headphones", price: 99.99, description: "Noise-cancelling over-ear headphones." },
                { id: 2, name: "Smart Watch", price: 199.50, description: "Fitness tracker with heart rate monitor." },
                { id: 3, name: "Bluetooth Speaker", price: 49.99, description: "Portable waterproof speaker with deep bass." },
                { id: 4, name: "E-Reader", price: 129.00, description: "High-resolution display with adjustable light." },
                { id: 5, name: "Laptop Stand", price: 35.00, description: "Ergonomic aluminum stand for all laptops." },
                { id: 6, name: "Mechanical Keyboard", price: 149.99, description: "RGB backlit tactile switches." },
            ];
            setProducts(mockProducts);
            setIsLoading(false);
        }, 1500);

        // Cleanup function
        return () => clearTimeout(timer);
    }, []); // Empty dependency array means this runs once

    // Handler for adding items to the cart
    const handleAddToCart = (product) => {
        setCartCount(prevCount => prevCount + 1);
        console.log(`Added to cart: ${product.name}`);
        // In a real app, this would update a cart context or state
    };

    // Derived state: Filtering products based on the search term
    const filteredProducts = products.filter(product =>
        product.name.toLowerCase().includes(searchTerm.toLowerCase())
    );

    return (
        <div class="min-h-screen">
            {/* Header / Navbar */}
            <header class="bg-white shadow-sm sticky top-0 z-10 border-b border-gray-100">
                <nav class="container mx-auto px-6 py-4 flex items-center justify-between">
                    <h1 class="text-2xl font-bold text-gray-950 flex items-center gap-2">
                        <span class="text-blue-600">⚛️</span> JS React Showcase
                    </h1>
                    <div class="flex items-center gap-4">
                        <span class="text-sm text-gray-600">Items in Cart:</span>
                        <div class="relative">
                            <span class="text-2xl">🛒</span>
                            {cartCount > 0 && (
                                <span class="absolute -top-2 -right-2 bg-red-600 text-white text-xs font-bold rounded-full w-5 h-5 flex items-center justify-center">
                                    {cartCount}
                                </span>
                            )}
                        </div>
                    </div>
                </nav>
            </header>

            {/* Main Content */}
            <main class="container mx-auto px-6 py-10">
                
                {/* Search and Filter Section */}
                <section class="mb-10 bg-white p-6 rounded-2xl shadow-sm border border-gray-100 flex flex-col md:flex-row gap-4 items-center justify-between">
                    <div class="w-full md:w-1/2">
                        <label htmlFor="search" class="block text-sm font-medium text-gray-700 mb-1">Search Products</label>
                        <input 
                            type="text" 
                            id="search"
                            value={searchTerm}
                            onChange={(e) => setSearchTerm(e.target.value)}
                            placeholder="Type product name... (e.g., 'Watch')" 
                            class="w-full px-4 py-2.5 border border-gray-300 rounded-lg focus:ring-2 focus:ring-blue-200 focus:border-blue-400 transition"
                        />
                    </div>
                    <div class="text-sm text-gray-500 text-center md:text-right">
                        Showing {filteredProducts.length} of {products.length} products
                    </div>
                </section>

                {/* Product Grid */}
                {isLoading ? (
                    // Loading State
                    <div class="text-center py-20">
                        <div class="animate-spin inline-block w-8 h-8 border-[3px] border-current border-t-transparent text-blue-600 rounded-full" role="status" aria-label="loading"></div>
                        <p class="mt-4 text-gray-600">Simulating API fetch...</p>
                    </div>
                ) : filteredProducts.length > 0 ? (
                    // Grid Rendering
                    <section class="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 xl:grid-cols-4 gap-8">
                        {filteredProducts.map(product => (
                            <ProductCard 
                                key={product.id} 
                                product={product} 
                                onAddToCart={handleAddToCart} 
                            />
                        ))}
                    </section>
                ) : (
                    // Empty/No Results State
                    <div class="text-center py-20 bg-white rounded-2xl border border-gray-100 shadow-sm">
                        <span class="text-5xl block mb-4">🔍</span>
                        <h2 class="text-xl font-semibold text-gray-800">No products found.</h2>
                        <p class="text-gray-600 mt-2">Try adjusting your search term.</p>
                    </div>
                )}
            </main>

            {/* Footer */}
            <footer class="mt-16 py-8 bg-gray-100 border-t border-gray-200">
                <div class="container mx-auto px-6 text-center text-sm text-gray-500">
                    Built with pure React (JavaScript/JSX) to demonstrate core concepts and balance language stats.
                </div>
            </footer>
        </div>
    );
};

// Rendering the main application into the root element
const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<App />);
