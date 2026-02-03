#include "catch.hpp"
#include "Image.hpp"
#include <fstream>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

// Test fixture with helper functions and constants
class ImageTestFixture {
public:
    // Test image paths
    static constexpr const char* BABOON_PATH = "/Users/kcourter/dev/upskill/data/test_images/standard/baboon.jpg";
    static constexpr const char* NONEXISTENT_PATH = "/nonexistent/path/image.jpg";
    static constexpr const char* TEST_OUTPUT_DIR = "/Users/kcourter/dev/upskill/build/test_output";
    static constexpr const char* TEST_WRITE_PNG = "/Users/kcourter/dev/upskill/build/test_output/test_write.png";

    // Ensure test output directory exists
    static void createOutputDir() {
        fs::create_directories(TEST_OUTPUT_DIR);
    }

    // Check if file exists
    static bool fileExists(const std::string& path) {
        std::ifstream file(path);
        return file.good();
    }
};

TEST_CASE("Image Constructor", "[image][constructor]") {

    SECTION("Constructor loads valid image successfully") {
        REQUIRE_NOTHROW([&]() {
            Image img(ImageTestFixture::BABOON_PATH);

            // Verify dimensions through stream output
            std::ostringstream oss;
            oss << img;
            std::string output = oss.str();

            REQUIRE(output.find("rows: 512") != std::string::npos);
            REQUIRE(output.find("cols: 512") != std::string::npos);
            REQUIRE(output.find("channels: 3") != std::string::npos);
        }());
    }

    SECTION("Constructor throws for non-existent file") {
        REQUIRE_THROWS_AS(
            Image(ImageTestFixture::NONEXISTENT_PATH),
            std::runtime_error
        );

        try {
            Image img(ImageTestFixture::NONEXISTENT_PATH);
        } catch (const std::runtime_error& e) {
            std::string error_msg = e.what();
            REQUIRE(error_msg.find(ImageTestFixture::NONEXISTENT_PATH) != std::string::npos);
        }
    }
}

TEST_CASE("Image Write", "[image][write]") {
    ImageTestFixture::createOutputDir();

    // Load baboon image
    Image img(ImageTestFixture::BABOON_PATH);

    SECTION("Write PNG creates valid file") {
        // Write the image
        REQUIRE_NOTHROW(img.write(ImageTestFixture::TEST_WRITE_PNG, Image::ImgType::PNG));

        // Verify file exists
        REQUIRE(ImageTestFixture::fileExists(ImageTestFixture::TEST_WRITE_PNG));

        // Verify we can load the written file
        REQUIRE_NOTHROW([&]() {
            Image reloaded(ImageTestFixture::TEST_WRITE_PNG);

            // Verify dimensions match original
            std::ostringstream oss;
            oss << reloaded;
            std::string output = oss.str();

            REQUIRE(output.find("rows: 512") != std::string::npos);
            REQUIRE(output.find("cols: 512") != std::string::npos);
            REQUIRE(output.find("channels: 3") != std::string::npos);
        }());
    }
}

TEST_CASE("Image Stream Output", "[image][stream]") {
    Image img(ImageTestFixture::BABOON_PATH);

    std::ostringstream oss;
    oss << img;
    std::string output = oss.str();

    REQUIRE(output.find("rows: 512") != std::string::npos);
    REQUIRE(output.find("cols: 512") != std::string::npos);
    REQUIRE(output.find("channels: 3") != std::string::npos);
    REQUIRE(output.find("img_path:") != std::string::npos);
    REQUIRE(output.find(ImageTestFixture::BABOON_PATH) != std::string::npos);
}
