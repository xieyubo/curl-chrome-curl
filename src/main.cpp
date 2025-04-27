#include <cstring>
#include <string>
#include <vector>

extern "C" int tool_main(int argc, char *argv[]);

int main(int argc, char *argv[])
{
    int chromeOptIndex{-1};
    for (auto i = 1; i < argc; ++i)
    {
        if (!strcmp(argv[i], "--chrome"))
        {
            chromeOptIndex = i;
            break;
        }
    }

    if (chromeOptIndex == -1)
    {
        return tool_main(argc, argv);
    }
    else
    {
        std::vector<const char *> args;
        args.emplace_back(argv[0]);

        args.emplace_back("--http2");
        args.emplace_back("--http2-no-server-push");
        args.emplace_back("--compressed");
        args.emplace_back("--tlsv1.2");
        args.emplace_back("--alps");
        args.emplace_back("--tls-permute-extensions");

        args.emplace_back("--ciphers");
        args.emplace_back(R"(TLS_AES_128_GCM_SHA256,TLS_AES_256_GCM_SHA384,TLS_CHACHA20_POLY1305_SHA256,ECDHE-ECDSA-AES128-GCM-SHA256,ECDHE-RSA-AES128-GCM-SHA256,ECDHE-ECDSA-AES256-GCM-SHA384,ECDHE-RSA-AES256-GCM-SHA384,ECDHE-ECDSA-CHACHA20-POLY1305,ECDHE-RSA-CHACHA20-POLY1305,ECDHE-RSA-AES128-SHA,ECDHE-RSA-AES256-SHA,AES128-GCM-SHA256,AES256-GCM-SHA384,AES128-SHA,AES256-SHA)");

        args.emplace_back("--cert-compression");
        args.emplace_back("brotli");

        args.emplace_back("-H");
        args.emplace_back(R"(User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/130.0.0.0 Safari/537.36)");

        args.emplace_back("-H");
        args.emplace_back(R"(Accept-Encoding: gzip, deflate, br, zstd)");

        args.emplace_back("-H");
        args.emplace_back(R"(Accept-Language: en-US,en;q=0.9)");

        args.emplace_back("-H");
        args.emplace_back(R"(Upgrade-Insecure-Requests: 1)");

        args.emplace_back("-H");
        args.emplace_back(R"(sec-ch-ua: "Chromium";v="130", "Google Chrome";v="130", "Not?A_Brand";v="99")");

        args.emplace_back("-H");
        args.emplace_back(R"(sec-ch-ua-mobile: ?0)");

        args.emplace_back("-H");
        args.emplace_back(R"(sec-ch-ua-platform: "Windows")");

        args.emplace_back("-H");
        args.emplace_back(R"(sec-fetch-site: none)");

        args.emplace_back("-H");
        args.emplace_back(R"(sec-fetch-mode: navigate)");

        args.emplace_back("-H");
        args.emplace_back(R"(sec-fetch-user: ?1)");

        args.emplace_back("-H");
        args.emplace_back(R"(sec-fetch-dest: document)");

        args.emplace_back("-H");
        args.emplace_back(R"(priority: u=0, i)");

        for (auto i = 1; i < argc; ++i)
        {
            if (i != chromeOptIndex)
            {
                args.emplace_back(argv[i]);
            }
        }

        args.emplace_back(nullptr);

        return tool_main(args.size() - 1, (char **)args.data());
    }
}